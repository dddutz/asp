// Converts image indices to/from row/column and deals with image rescaling

#ifndef IMAGE_INDEXER_H_
#define IMAGE_INDEXER_H_

#include "ros/assert.h"
#include "cxcore.h"
//namespace cv {
//template<typename _Tp> class Mat_;
//typedef Mat_<Vec3b> Mat3b;
//}

class ImageIndexer
{
public:
  ImageIndexer(int src_width, int dst_width)
      : src_width_(src_width), dst_width_(dst_width), scale_factor_(0) {
    if (src_width < dst_width) {
      ROS_ASSERT(dst_width % src_width == 0);
      scale_factor_ = dst_width / src_width;
    } else if (src_width > dst_width) {
      ROS_ASSERT(src_width % dst_width == 0);
      scale_factor_ = src_width / dst_width;
    }
  }
  // converts index for one image into an index for a different-size image
  // e.g. QVGA to VGA
  inline int scale(int src_idx)
  {
    if (src_width_ < dst_width_) {
      int src_col = src_idx % src_width_;
      int src_row = src_idx / src_width_;
      return scale_factor_ * (src_col + src_row * dst_width_);
    } else if (src_width_ > dst_width_) {
      int src_col = src_idx % src_width_;
      int src_row = src_idx / src_width_;
      return (src_col / scale_factor_) + (src_row / scale_factor_) * dst_width_;
    } else return src_idx;
  }

  inline void packColorFromMatrix(const cv::Mat3b &src_mat, int src_start_depth_index,
                                  uint8_t *dst_packed_array,
                                  int dst_depth_array_index)
  {
    int src_start_index = scale(src_start_depth_index);
    int dst_start_index = scale_factor_ * scale_factor_ * dst_depth_array_index;

    for (int dy = 0; dy < scale_factor_; dy++) {
      for (int dx = 0; dx < scale_factor_; dx++) {
        int src_idx = (src_start_index + dy * dst_width_ + dx);
        int dst_idx = (dst_start_index + dy * scale_factor_ + dx) * 3;

        dst_packed_array[dst_idx + 0] = src_mat(src_idx)[0];
        dst_packed_array[dst_idx + 1] = src_mat(src_idx)[1];
        dst_packed_array[dst_idx + 2] = src_mat(src_idx)[2];
      }
    }
  }

  inline void packColorFromImage(const uint8_t *src_img, int src_start_depth_index,
                                 uint8_t *dst_packed_array,
                                 int dst_depth_array_index)
  {
    int src_start_index = scale(src_start_depth_index);
    int dst_start_index = scale_factor_ * scale_factor_ * dst_depth_array_index;

    for (int dy = 0; dy < scale_factor_; dy++) {
      for (int dx = 0; dx < scale_factor_; dx++) {
        int src_idx = (src_start_index + dy * dst_width_ + dx) * 3;
        int dst_idx = (dst_start_index + dy * scale_factor_ + dx) * 3;

        dst_packed_array[dst_idx + 2] = src_img[src_idx + 0];
        dst_packed_array[dst_idx + 1] = src_img[src_idx + 1];
        dst_packed_array[dst_idx + 0] = src_img[src_idx + 2];
      }
    }
  }

  inline void unpackColorIntoRGB(const uint8_t *src_packed_array,
                                   int src_depth_array_index,
                                   uint8_t *dst_img,
                                   int dst_start_depth_index)
  {
    int src_start_index = scale_factor_ * scale_factor_ * src_depth_array_index;
    int dst_start_index = scale(dst_start_depth_index);

    for (int dy = 0; dy < scale_factor_; dy++) {
      for (int dx = 0; dx < scale_factor_; dx++) {
        int src_idx = (src_start_index + dy * scale_factor_ + dx) * 3;
        int dst_idx = (dst_start_index + dy * dst_width_ + dx) * 3;

        dst_img[dst_idx + 0] = src_packed_array[src_idx + 0];
        dst_img[dst_idx + 1] = src_packed_array[src_idx + 1];
        dst_img[dst_idx + 2] = src_packed_array[src_idx + 2];
      }
    }
  }

  inline void unpackColorIntoRGBA(const uint8_t *src_packed_array,
                                   int src_depth_array_index,
                                   uint8_t *dst_img,
                                   int dst_start_depth_index,
                                   uint8_t alpha)
  {
    int src_start_index = scale_factor_ * scale_factor_ * src_depth_array_index;
    int dst_start_index = scale(dst_start_depth_index);

    for (int dy = 0; dy < scale_factor_; dy++) {
      for (int dx = 0; dx < scale_factor_; dx++) {
        int src_idx = (src_start_index + dy * scale_factor_ + dx) * 3;
        int dst_idx = (dst_start_index + dy * dst_width_ + dx) * 4;

        dst_img[dst_idx + 0] = src_packed_array[src_idx + 2];
        dst_img[dst_idx + 1] = src_packed_array[src_idx + 1];
        dst_img[dst_idx + 2] = src_packed_array[src_idx + 0];
        dst_img[dst_idx + 3] = alpha;
      }
    }
  }

  inline void unpackColorIntoMatrix(const uint8_t *src_packed_array,
                                    int src_depth_array_index,
                                    cv::Mat3b &dst_mat,
                                    int dst_start_depth_index)
  {
    int src_start_index = scale_factor_ * scale_factor_ * src_depth_array_index;
    int dst_start_index = scale(dst_start_depth_index);

    for (int dy = 0; dy < scale_factor_; dy++) {
      for (int dx = 0; dx < scale_factor_; dx++) {
        int src_idx = (src_start_index + dy * scale_factor_ + dx) * 3;
        int dst_idx = (dst_start_index + dy * dst_width_ + dx);

        dst_mat(dst_idx)[0] = src_packed_array[src_idx + 0];
        dst_mat(dst_idx)[1] = src_packed_array[src_idx + 1];
        dst_mat(dst_idx)[2] = src_packed_array[src_idx + 2];
      }
    }
  }

private:
  int src_width_, dst_width_;
  int scale_factor_;
};



#endif /* IMAGE_INDEXER_H_ */

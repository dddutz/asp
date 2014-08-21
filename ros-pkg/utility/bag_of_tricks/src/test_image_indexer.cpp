#include <bag_of_tricks/image_indexer.h>
#include <gtest/gtest.h>
#include <ros/assert.h>

using namespace std;

TEST(ImageIndexer, ImageIndexer)
{
  {
    ImageIndexer ii(320, 320);
    for (int i = 0; i < 100; i++) {
      int r = rand() % (320 * 240);
      EXPECT_EQ(ii.scale(r), r);
    }
  }

  {
    ImageIndexer ii(640, 320);
    for (int i = 0; i < 100; i++) {
      int r = rand() % (640 * 480);
      EXPECT_EQ(ii.scale(r),
                (r / 640) / 2 * 320 + (r % 640) / 2) << "Fail for r=" << r;
    }

    EXPECT_EQ(ii.scale(42), 21);
    EXPECT_EQ(ii.scale(640), 0);
    EXPECT_EQ(ii.scale(641), 0);
    EXPECT_EQ(ii.scale(642), 1);
    EXPECT_EQ(ii.scale(1280+42), 320+21);
  }


  {
    ImageIndexer ii(320, 640);
    for (int i = 0; i < 100; i++) {
      int r = rand() % (320 * 240);
      EXPECT_EQ(ii.scale(r), r / 320 * 2 * 640 + (r%320)*2);
    }
    for (int i = 0; i < 100; i++) {
      int r = rand() % (320 * 240);
      EXPECT_EQ(ii.scale(r), r / 320 * 2 * 640 + (r%320)*2);
    }

    EXPECT_EQ(ii.scale(42), 84);
    EXPECT_EQ(ii.scale(640), 640*4);
    EXPECT_EQ(ii.scale(642), 640*4 + 2*2);
    EXPECT_EQ(ii.scale(1280+42), 1280*4 + 42*2);
  }
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

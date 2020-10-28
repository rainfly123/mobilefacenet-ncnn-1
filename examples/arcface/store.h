#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "base.h"

using namespace std;

enum Mode{
    READ = 1,
    WRITE = 2
};

class  Store {
    public :
          Store(const char *file, Mode mode);
          ~Store();
    public :
          int dump(vector<FaceFeature> &gFeatures);
          int load(vector<FaceFeature> &gFeatures);
          void flush(void);
    private:
          fstream inout;
          string   filename;
};

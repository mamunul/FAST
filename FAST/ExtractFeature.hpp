//
//  extractFeature.hpp
//  FAST
//
//  Created by Mamunul on 4/2/18.
//  Copyright © 2018 Mamunul. All rights reserved.
//

#ifndef extractFeature_hpp
#define extractFeature_hpp

#include <stdio.h>
//#include "gvars3.h"
#include <cvd/image_io.h>
#include <cvd/fast_corner.h>
#include <stdint.h>
#include <map>
#include <iterator>
#include <string>
#include "Types.h"

using namespace std;
using namespace CVD;
//using namespace GVars3;

map<string, corner> extractFeature(vector<string> img_path_list);

#endif /* extractFeature_hpp */

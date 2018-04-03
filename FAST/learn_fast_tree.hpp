//
//  Header.h
//  FAST
//
//  Created by Mamunul on 4/2/18.
//  Copyright © 2018 Mamunul. All rights reserved.
//

#ifndef Header_h
#define Header_h


#include <iostream>
#include <sstream>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <string>
#include <memory>
#include <cmath>
#include <stdint.h>

#include <cvd/image_ref.h>

//#include "gvars3.h"
#include "varprintf.h"
#include "Types.h"

using namespace std;
using namespace varPrintf;
using namespace CVD;
//using namespace GVars3;

shared_ptr<tree> buildTreeFrom(int num_features, vector<ImageRef> offsets, map<string, corner> corners);
void print_tree(const tree* node, ostream& o, const string& i="");
#endif /* Header_h */

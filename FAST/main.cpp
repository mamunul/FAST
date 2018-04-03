//
//  main.cpp
//  FAST
//
//  Created by Mamunul on 4/2/18.
//  Copyright © 2018 Mamunul. All rights reserved.
//

#include <stdio.h>
#include "ExtractFeature.hpp"
#include "learn_fast_tree.hpp"
#include "Types.h"

int main(){
	
	map<string, corner> corners = extractFeature();
	vector<ImageRef> offsets = vector<ImageRef>(16);
	
	for (int i = 0;i<16;i++){
		offsets[i] = fast_pixel_ring[i];
	}
	int num_features = 16;
	shared_ptr<tree> tree = buildTreeFrom(num_features, offsets,corners);
	print_tree(tree.get(), cout);
	return 0;
	
	
}

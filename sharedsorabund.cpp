/*
 *  sharedsorabund.cpp
 *  Dotur
 *
 *  Created by Sarah Westcott on 1/8/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "sharedsorabund.h"

/***********************************************************************/

EstOutput SorAbund::getValues(vector<SharedRAbundVector*> shared) {
	try {
		EstOutput UVest;
		UVest.resize(2,0);
		data.resize(1,0);
		
		UVest = uv->getUVest(shared);
		
		//UVest[0] is Uest, UVest[1] is Vest
		data[0] = (2 * UVest[0] * UVest[1]) / ((float)(UVest[0] + UVest[1]));
		
		if (isnan(data[0]) || isinf(data[0])) { data[0] = 0; }
		
		return data;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the SorAbund class Function getValues. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the SorAbund class Function getValues. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}

/***********************************************************************/


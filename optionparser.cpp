/*
 *  optionparser.cpp
 *  Mothur
 *
 *  Created by Sarah Westcott on 6/8/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "optionparser.h"

/***********************************************************************/

OptionParser::OptionParser(string option) {
	try {
		
		if (option != "") {
			
			string key, value;		
			//reads in parameters and values
			while((option.find_first_of(',') != -1)) {  //while there are parameters
				splitAtComma(value, option);
				splitAtEquals(key, value);
				parameters[key] = value;
			}
			
			//in case there is no comma and to get last parameter after comma
			splitAtEquals(key, option);
			parameters[key] = option;
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the OptionParser class Function parse. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the OptionParser class function parse. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
}

/***********************************************************************/

map<string, string> OptionParser::getParameters() {	return parameters;	}

/***********************************************************************/
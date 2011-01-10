#ifndef PCOACOMMAND_H
#define PCOACOMMAND_H

/*
 *  pcoacommand.h
 *  Mothur
 *
 *  Created by westcott on 1/4/10.
 *  Copyright 2010 Schloss Lab. All rights reserved.
 *
 */
 
#include "command.hpp"
#include "linearalgebra.h"


/*****************************************************************/
class PCOACommand : public Command {
	
public:
	PCOACommand(string);	
	PCOACommand();
	~PCOACommand();
	vector<string> getRequiredParameters();
	vector<string> getValidParameters();
	vector<string> getRequiredFiles();
	map<string, vector<string> > getOutputFiles() { return outputTypes; }
	int execute();	
	void help();
	
private:

	bool abort, metric;
	string phylipfile, columnfile, namefile, format, filename, fbase, outputDir;
	float cutoff, precision;
	vector<string> outputNames;
	map<string, vector<string> > outputTypes;
	LinearAlgebra linearCalc;
	
	void get_comment(istream&, char, char);
	int read_phylip(istream&, int, vector<string>&, vector<vector<double> >&);
	void read(string, vector<string>&, vector<vector<double> >&);
	void recenter(double, vector<vector<double> >, vector<vector<double> >&);
	void output(string, vector<string>, vector<vector<double> >&, vector<double>);
	
};
	
/*****************************************************************/
	
#endif

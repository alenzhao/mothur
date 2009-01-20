#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

/*
 *  commandfactory.h
 *  
 *
 *  Created by Pat Schloss on 10/25/08.
 *  Copyright 2008 Patrick D. Schloss. All rights reserved.
 *
 */

class Command;

class CommandFactory {
public:
	CommandFactory();
	~CommandFactory();
	Command* getCommand(string);
private:
	Command* command;

};

#endif
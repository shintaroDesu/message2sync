/*
 * Bash.h
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#ifndef SRC_KOUHAI_COMMANDS_BASH_BASH_H_
#define SRC_KOUHAI_COMMANDS_BASH_BASH_H_

#include "../../abstracts/ACommand.h"

// run shell command
class Bash : public ACommand {
private:
	std::string exec(const char* cmd);

public:
	Bash();

	~Bash() override;

	std::string run(std::string &my_string) final;
};

#endif /* SRC_COMMANDS_BASH_H_ */

#ifndef __ACTION__
#define __ACTION__

class Action{
public:

	static Action DescribeAction(std::string description){
		return Action(description);
	}

	std::string GetDescription(){
		return description;
	}
private:
	Action(std::string description):description(description){}
	std::string description;
};

#endif
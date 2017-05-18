/*******************************************************************************************
                           ------   ------   ------  ------
                          |      | |               |       |
                          |      | |               |       |
                           ------   ------   ------        |
                                 |        | |              |
                                 |        | |              |
                           ------   ------   ------        |
*Created by SeanInChina Liu
*Date 2016.8
*Copyright XiaoLiu
********************************************************************************************/
#ifndef _UTILS_HPP_
#define _UTILS_HPP_
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <omp.h>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <glog/logging.h>
//-lglog

using namespace std;
namespace utils{
	
class UTILS{
	public:
		boost::posix_time::ptime start_time_;
		boost::posix_time::ptime end_time_;
		bool isexist(string path)
		{
			if(access(path.c_str(), 0) == 0)
				return true;
		}
		void Start()
		{
			start_time_ = boost::posix_time::microsec_clock::local_time();
		}
		void Stop()
		{
			end_time_ = boost::posix_time::microsec_clock::local_time();
		}
		void RunTime()
		{
            std::cout<<end_time_ - start_time_<<std::endl;
		}
		
		void split(string& s, string& delim, vector<string>& ret)
		{
			int separate_characterLen = delim.size();//分割字符串长度，这样就可以支持多字 符串的分隔符
			int lastPosition = 0, index = -1;
			while (-1 != (index = s.find(delim, lastPosition)))
			{
				ret.push_back(s.substr(lastPosition, index - lastPosition));
				lastPosition = index + separate_characterLen;
			}
			string lastString = s.substr(lastPosition);
			if (!lastString.empty())
			ret.push_back(lastString);
		}

		string num2str(int& i)
		{
			std::stringstream ss;
			ss<<i;
			return ss.str();
		}
		
		string num2str(float& i)
		{
			std::stringstream ss;
			ss<<i;
			return ss.str();
		}
		
		string num2str(double& i)
		{
			std::stringstream ss;
			ss<<i;
			return ss.str();
		}

		int str2int(string& str)
		{
			return atoi(str.c_str());
		}
	};
}
#endif

/*
 *The MIT License (MIT)
 *
 *Copyright (c) 2014 MALLER
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
 *
 */

#include <stdio.h>
#include <unistd.h>
#include "dev/freshplayer-installer-seeker.c"

int main(int argc,char* argv[])
{
	char install[]="cd ~ && mkdir freshplayerplugin && cd freshplayerplugin && wget https://codeload.github.com/i-rinat/freshplayerplugin/zip/master && unzip master && cd freshplayerplugin-master && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo .. && make && cp -f libfreshwrapper-pepperflash.so ~/.mozilla/plugins/libfreshwrapper-pepperflash.so && cd .. && cd .. && cd .. && rm -R freshplayerplugin/ && echo Freshplayer was successfully installed";
	char uninstall[]="rm -f ~/.mozilla/plugins/libfreshwrapper-pepperflash.so";
	char install_flash[]="apt-get install flashplugin-nonfree";
	int seeker;
	seeker=SEEKER();
	
	if(argc==1)
	{
		printf("\n\t\t\x1b[1;31mfreshplayer-installer argument is missing, try with \"freshplayer install\"\x1b[0;0m\n\n");
		return(0);
	}
	else
	{
		if(strcmp("install",argv[1])==0)
		{
			if(seeker==0)
			{
				printf("\n\n\tAn error has ocurred, please report it to:\n\thttps://github.com/MALLER-LAGOON/Freshplayer-installer/issues\n\twith the details of the error. i'll be really greatful if u do it :)\n\n");
				return 0;
			}
			else if(seeker==1)
			{
				system(install);
				return 0;
			}
		}
		else if(strcmp("uninstall",argv[1])==0)
		{
			system(uninstall);
			printf("\n\n\t\t\x1b[1;32mFreshplayerplugin was successfully removed\x1b[0;0m\n\n");
			if(getuid()!=0)
			{
				system(install_flash);
				return 0;
			}
			return 0;
		}
		else
		{
			printf("\n\t\t\x1b[1;33mThe argument entered \x1b[1;31mIS NOT VALID\n\t\t\t\x1b[1;33mtry with \"freshplayer install\"\x1b[0;0m\n\n");
			return 0;
		}
	}
	return 0;
}

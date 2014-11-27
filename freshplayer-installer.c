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

int main(int argc,char* argv[])
{
	char update[]="cd ~ && mkdir freshplayerplugin && cd freshplayerplugin && wget https://codeload.github.com/i-rinat/freshplayerplugin/zip/master && unzip master && cd freshplayerplugin-master && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo .. && make && cp -f libfreshwrapper-pepperflash.so ~/.mozilla/plugins/libfreshwrapper-pepperflash.so && cp -f libfreshwrapper-pepperflash.so ~/freshplayerplugin/libfreshwrapper-pepperflash.so && cd .. && cd .. && cd .. && rm -R freshplayerplugin/";

	if(argc==1)
	{
		printf("\n\t\t\x1b[1;31mNo colocaste la instruccion\x1b[0;0m\n\n");
		return(0);
	}
	else
	{
		if(strcmp("install",argv[1])==0)
		{
			system(update);
			return 0;
		}
		else
		{
			printf("\n\t\t\x1b[1;31mThe argument entered IS NOT VALID\x1b[0;0m\n\n");
			return 0;
		}
	}
}

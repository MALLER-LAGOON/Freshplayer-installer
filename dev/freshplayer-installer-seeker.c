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
#include <stdlib.h>
#include <string.h>

int SEEKER(void);
int FRESHPLAYERPLUGIN(void);
int PLUGINS(void);
int FRESHWRAPPER(void);

int SEEKER(void)
{
	int freshplayerplugin, plugins, freshwrapper;
	freshplayerplugin=FRESHPLAYERPLUGIN();
	plugins=PLUGINS();
	freshwrapper=FRESHWRAPPER();

	if(freshplayerplugin==0)
	{
		if(plugins==0)
		{
			system("mkdir ~/.mozilla/plugins");
			return 1;
		}
		else
		{
			if(freshwrapper==0)
			{
				return 1;
			}
			else
			{
				system("rm -R ~/.mozilla/plugins/libfreshwrapper-pepperflash.so");
				return 1;
			}
		}
	}
	else
	{
		system("rm -R ~/freshplayerplugin");
		if(plugins==0)
		{
			system("mkdir ~/.mozilla/plugins");
			return 1;
		}
		else
		{
			if(freshwrapper==0)
			{
				return 1;
			}
			else
			{
				system("rm -R ~/.mozilla/plugins/libfreshwrapper-pepperflash.so");
				return 1;
			}
		}
	}
	return 0;
}

int FRESHWRAPPER(void) /*encuentra el plugin*/
{
	FILE *DIR=NULL;
	char aux[1000];

	DIR=popen("cd ~/.mozilla/plugins && ls", "r");
	fgets(aux, 1000, DIR);

	while(!feof(DIR))
	{
		if(strstr(aux,"libfreshwrapper-pepperflash.so")!=NULL)
		{
			return 1;
			break;
		}
		fgets(aux, 1000, DIR);
	}
	pclose(DIR);
	return 0;
}

int PLUGINS(void) /*encuentra la carpeta plugins*/
{
	FILE *DIR=NULL;
	char aux[1000];

	DIR=popen("cd ~/.mozilla/ && ls", "r");
	fgets(aux, 1000, DIR);

	while(!feof(DIR))
	{
		if(strstr(aux,"plugins")!=NULL)
		{
			return 1;
			break;
		}
		fgets(aux, 1000, DIR);
	}
	pclose(DIR);
	return 0;
}

int FRESHPLAYERPLUGIN(void) /*encuentra la carpeta supuestamente temporal*/
{
	FILE *DIR=NULL;
	char aux[1000];

	DIR=popen("cd ~ && ls", "r");
	fgets(aux, 1000, DIR);

	while(!feof(DIR))
	{
		if(strstr(aux,"freshplayerplugin")!=NULL)
		{
			return 1;
			break;
		}
		fgets(aux, 1000, DIR);
	}
	pclose(DIR);
	return 0;
}

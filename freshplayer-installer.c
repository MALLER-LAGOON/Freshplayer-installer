/*The MIT License (MIT)
 *
 *Copyright (c) 2014-2015 MALLER
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
 */

#include <stdio.h>
#include <unistd.h>
#include "dev/freshplayer-installer-seeker.c"
#include "dev/freshplayer-installer-commit.c"
#include "dev/freshplayer-installer-options.c"

int main(int argc,char* argv[])
{
	int seeker;
	
	if(argc==1)
	{
		printf("\n\t\t\x1b[1;31mfreshplayer-installer argument is missing, try with \"freshplayer install\"\x1b[0;0m\n\n");
		return(0);
	}
	else
	{
		if(argc==2 && strcmp("install",argv[1])==0)
		{
			seeker=SEEKER();
			if(seeker==0)
			{
				printf("\n\n\t\x1b[1;33mAn error has ocurred, please report it to:\n\thttps://github.com/MALLER-LAGOON/Freshplayer-installer/issues\n\twith the details of the error. i'll be really greatful if u do it :)\x1b[0;0m\n\n");
				return 0;
			}
			else if(seeker==1)
			{
				INSTALL();
				return 0;
			}
		}
		else if(argc==2 && strcmp("install-gtk3",argv[1])==0)
		{
			seeker=SEEKER();
			if(seeker==0)
			{
				printf("\n\n\t\x1b[1;33mAn error has ocurred, please report it to:\n\thttps://github.com/MALLER-LAGOON/Freshplayer-installer/issues\n\twith the details of the error. i'll be really greatful if u do it :)\x1b[0;0m\n\n");
				return 0;
			}
			else if(seeker==1)
			{
				INSTALL_GTK3();
				return 0;
			}
		}
		else if(strcmp("uninstall",argv[1])==0)
		{
			UNINSTALL();
			printf("\n\n\t\t\x1b[1;32mFreshplayerplugin was successfully removed\x1b[0;0m\n\n");
			if(getuid()!=0)
			{
				INSTALL_FLASH();
				return 0;
			}
			return 0;
		}
		else if(strcmp("--commit",argv[1])==0 || strcmp("-c",argv[1])==0)
		{
			seeker=SEEKER();
			if(seeker==0)
				{
					printf("\n\n\t\x1b[1;33mAn error has ocurred, please report it to:\n\thttps://github.com/MALLER-LAGOON/Freshplayer-installer/issues\n\twith the details of the error. i'll be really greatful if u do it :)\x1b[0;0m\n\n");
					return 0;
				}
			else if(seeker==1)
			{
				if(strlen(argv[2])<40)
				{
					printf( "\n\n\tthe entered commit \x1b[1;33m%s\x1b[0;0m, is not valid.\n\n",argv[2]);
					COMMIT_MSG();
				}
				else
				{
					// FALTA AUN:
					// - verificar la existencia del enlace al commit o indicar el respectivo error
					// y realizar las comprobaciones necesarias (bendito sea WGET)
					COMMIT_DWLD(argv[2]);
					return 0;
				}
			}
		}
		else if(strcmp("--help",argv[1])==0||strcmp("-h",argv[1])==0)
		{
			// FALTA:
			// realizar un menu de ayuda decente, en donde se presenten los argumentos para el comando freshplayer
			COMMIT_MSG();
		}
		else if(argc>2)
		{
			printf( "\n\n\tel ingreso de parametros multiples aun se encuentran en desarrollo, pero aun estoy trabajando en el :).\n\n");
		}
		else
		{
			printf("\n\t\t\x1b[1;33mThe argument entered \x1b[1;31mIS NOT VALID\n\t\t\t\x1b[1;33mtry with \"$ freshplayer install\"\x1b[0;0m or \x1b[1;33m\"$ freshplayer --help\"\x1b[0;0m for more details\n\n");
			return 0;
		}
	}
	return 0;
}

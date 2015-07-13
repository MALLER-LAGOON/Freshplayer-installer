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
#include "dev/freshplayer-installer-options.c"

int main(int argc,char* argv[])
{
	int seeker, count, commit_arg, commit_SHA, install_val;
	int gtk3=0;
	int trace=0;
	int debug=0;
	int angle=0;
	int hwdec=0;
	int pulseaudio=0;
	int commit_val=0;

	if(argc==1)
	{
		printf("\n\t\t\x1b[1;31mfreshplayer-installer argument is missing, try with \x1b[1;32m\"\x1b[1;33mfreshplayer --help\x1b[1;32m\"\x1b[0;0m\n\n");
	}

	else if(argc>=2)
	{
		printf("\n");

		if(argc==2)
		{
			if(strcmp("install",argv[argc-1])==0)
			{
				seeker=SEEKER();
				switch (seeker)
				{
					case 0:{
						printf("\n\n\t\x1b[1;33mAn error has ocurred, please report it to:\n\thttps://github.com/MALLER-LAGOON/Freshplayer-installer/issues\n\twith the details of the error. i'll be really greatful if u do it :)\x1b[0;0m\n\n");
						return 0;
					}
					case 1:{
						INSTALL();
						break;
					}
				}
			}			
			else if(strcmp("uninstall",argv[argc-1])==0)
			{
				UNINSTALL();
				printf("\n\n\t\t\x1b[1;32mFreshplayerplugin was successfully removed\x1b[0;0m\n\n");
				if(getuid()!=0)
				{
					INSTALL_FLASH();
				}
			}
			else if(strcmp("--help",argv[1])==0||strcmp("-h",argv[1])==0)
			{
				// FALTA:
				// realizar un menu de ayuda decente, en donde se presenten los argumentos para el comando freshplayer
				HELP();
				COMMIT_MSG();
			}
			else
			{
				printf("\n\t\t\x1b[1;31mArgumento ingresado no valido, intenta con \x1b[1;32m\"\x1b[1;33mfreshplayer --help\x1b[1;32m\" \x1b[1;31mpara mayor informacion\n\n\x1b[0;0m");
			}
		}

		else if(3<=argc)
		{
			for(count=0;count<argc;count++)
			{
				if(strcmp("-gtk3",argv[count])==0)
				{
					gtk3=1;
				}
				else if(strcmp("-trace",argv[count])==0)
				{
					trace=1;
				}
				else if(strcmp("-debug",argv[count])==0)
				{
					debug=1;
				}
				else if(strcmp("-angle",argv[count])==0||strcmp("-gles2",argv[count])==0||strcmp("-gles",argv[count])==0||strcmp("-gl",argv[count])==0)
				{
					angle=1;
				}
				else if(strcmp("-hwdec",argv[count])==0)
				{
					hwdec=1;
				}
				else if(strcmp("-pulse",argv[count])==0)
				{
					pulseaudio=1;
				}
				else if(strcmp("--commit",argv[count])==0 || strcmp("-c",argv[count])==0)
				{
					commit_SHA=strlen(argv[count+1]);

					switch (commit_SHA)
					{
						case 40:{
									commit_val=1;
									commit_arg=count+1;
									break;
								}
						default:{
									printf( "\n\n\tthe entered commit \x1b[1;33m%s\x1b[0;0m, is not a valid commit SHA.\n\n",argv[count+1]);
									return(0);
								}
					}
				}
			}

			install_val=strcmp("install",argv[argc-1]);

			switch (install_val)
			{
				case 0: {
							switch (commit_val)
							{
								case 0: {
											seeker=SEEKER();
											switch (seeker)
											{
												case 0: {
															printf("\n\n\t\x1b[1;33mAn error has ocurred, please report it to:\n\thttps://github.com/MALLER-LAGOON/Freshplayer-installer/issues\n\twith the details of the error. i'll be really greatful if u do it :)\x1b[0;0m\n\n");
															break;
														}
												case 1: {
															SPECIAL_INSTALL(gtk3,trace,debug,angle,hwdec,pulseaudio);
															break;
														}
											}
											return(0);
										}
								case 1: {
											seeker=SEEKER();
											switch (seeker)
											{
												case 0: {
															printf("\n\n\t\x1b[1;33mAn error has ocurred, please report it to:\n\thttps://github.com/MALLER-LAGOON/Freshplayer-installer/issues\n\twith the details of the error. i'll be really greatful if u do it :)\x1b[0;0m\n\n");
															break;
														}
												case 1: {
															SPECIAL_COMMIT_INSTALL(gtk3,trace,debug,angle,hwdec,pulseaudio,argv[commit_arg]);
															break;
														}
											}
											return(0);
										}
							}
							break;
						}
				default:{
							printf("the argument \"install\" is missing");
							return 0;
						}
			}
		}
	}
	return 0;
}

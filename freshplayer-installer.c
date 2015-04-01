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

int main(int argc,char* argv[])
{
	char install[]=" echo && echo CREATING TEMPORAL FOLDER... && echo && cd ~ && mkdir freshplayerplugin && cd freshplayerplugin && echo DOWNLOADING SOURCE CODE... && echo && wget https://github.com/i-rinat/freshplayerplugin/archive/master.zip && echo UNCOMPRESSING SOURCE FILES... && echo && unzip master.zip && cd freshplayerplugin-master && mkdir build && cd build && echo && echo VERIFYING DEPENDENCIES AND CREATING MAKEFILE... && echo && cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DHAVE_PULSEAUDIO=1 .. && echo && echo CREATING FRESHPLAYER PLUGIN... && echo && make && echo && echo INSTALLING FRESHPLAYER PLUGIN... && echo && cp -f libfreshwrapper-pepperflash.so ~/.mozilla/plugins/libfreshwrapper-pepperflash.so && echo && echo REMOVING TEMPORAL FILES... && echo && cd .. && cd .. && cd .. && rm -R freshplayerplugin/ && echo && echo FRESHPLAYER HAS BEEN SUCCESSFULLY INSTALLED &&echo";
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
				printf("\n\n\t\x1b[1;33mAn error has ocurred, please report it to:\n\thttps://github.com/MALLER-LAGOON/Freshplayer-installer/issues\n\twith the details of the error. i'll be really greatful if u do it :)\x1b[0;0m\n\n");
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
		else if(strcmp("--commit",argv[1])==0 || strcmp("-c",argv[1])==0)
		{
			if(seeker==0)
				{
					printf("\n\n\t\x1b[1;33mAn error has ocurred, please report it to:\n\thttps://github.com/MALLER-LAGOON/Freshplayer-installer/issues\n\twith the details of the error. i'll be really greatful if u do it :)\x1b[0;0m\n\n");
					return 0;
				}
			else if(seeker==1)
			{
				// aqui es necesario definir una funcion que genere el enlace de descarga del commit
				// y tambien es necesario que tome el commit para poder hacer la descompresion de la carpeta
				// y posterior compilacion e instalacion
				// por lo tanto debe hacer:
				// - verificar longitud de la cadena del commit, la cual debe ser necesariamente mas grande que 8 caracteres
				//   de lo contrario, mostrar un mensaje que indique como obtener la verdadera cadena del commit.

				if(strlen(argv[2])<40)
				{
					printf( "\n\n\tthe entered commit \x1b[1;33m%s\x1b[0;0m, is not valid.\n\n",argv[2]);
					COMMIT_MSG();
				}
				else
				{
					// aqui se debe llamar una funcion que permita colocar la cadena de commit en el lugar adecuado
					// - verificar la existencia del enlace al commit o indicar el respectivo error
					// - si el enlace es valido, descargar, compilar e instalar el commit
					// y realizar las comprobaciones necesarias (bendito sea WGET)
					COMMIT_DWLD();
					//system(install_commit); /*esta llamada es necesariamente referencial*/
					return 0;
				}
			}
		}
		else if(strcmp("--help",argv[1])==0)
		{
			COMMIT_DWLD();
		}
		else
		{
			printf("\n\t\t\x1b[1;33mThe argument entered \x1b[1;31mIS NOT VALID\n\t\t\t\x1b[1;33mtry with \"$ freshplayer install\"\x1b[0;0m or \x1b[1;33m\"$ freshplayer --help\"\x1b[0;0m for more details\n\n");
			return 0;
		}
	}
	return 0;
}

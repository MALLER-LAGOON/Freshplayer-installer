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
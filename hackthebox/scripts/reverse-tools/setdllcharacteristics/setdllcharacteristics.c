/*
	setdllcharacteristics
	Source code put in public domain by Didier Stevens, no Copyright
	https://DidierStevens.com
	Use at your own risk

	Editor tab stop value = 2

	Shortcomings, or todo's ;-)

	History:
		2010/10/04 0.0.0.1 Start development
		2010/10/09 Replaced stricmp with strcmp for *nix compatibility
*/

#include <stdio.h>
#include <string.h>

#ifdef INCLUDE_RESOURCE
#pragma resource "setdllcharacteristics.res"
#endif

#define PEINDEX_POSITION 0x3C
#define DLLCHARACTERISTICS_OFFSET 0x5E

void DisplayFlags(unsigned short int wDLLCHARACTERISTICS)
{
	printf(" DYNAMIC_BASE    = %d\n", (wDLLCHARACTERISTICS & 0x40) == 0x40);
	printf(" NX_COMPAT       = %d\n", (wDLLCHARACTERISTICS & 0x100) == 0x100);
	printf(" FORCE_INTEGRITY = %d\n", (wDLLCHARACTERISTICS & 0x80) == 0x80);
}

int main(int argc, char *argv[])
{
	FILE *fPEFile;
	char *pszFilename;
	unsigned int uiPEHEADERIndex;
	unsigned short int wDLLCHARACTERISTICS;
	int iIter;

	if (1 == argc)
	{
		fprintf(stderr, "Usage: setdllcharacteristics [options] file\n"
							"setdllcharacteristics V0.0.0.1, set PE-file DLLCHARACTERISTICS like\n"
							" DYNAMIC_BASE (ASLR), NX_COMPAT (DEP) and FORCE_INTEGRITY (check signature).\n"
							"options:\n"
							" +d set DYNAMIC_BASE flag (ASLR)\n"
							" -d clear DYNAMIC_BASE flag (ASLR)\n"
							" +n set NX_COMPAT flag (DEP)\n"
							" -n clear NX_COMPAT flag (DEP)\n"
							" +f set FORCE_INTEGRITY flag (check signature)\n"
							" -f clear FORCE_INTEGRITY flag (check signature)\n"
							"Source code put in the public domain by Didier Stevens, no Copyright\n"
							"Use at your own risk\n"
							"http://didierstevens.com\n");
		return -1;
	}

	pszFilename = argv[argc-1];
	if ((fPEFile = fopen(pszFilename, "r+b")) == NULL)
	{
		fprintf(stderr, "Error: opening file %s\n", pszFilename);
		return -1;
	}

	if (fseek(fPEFile, PEINDEX_POSITION, 0) != 0)
	{
		fprintf(stderr, "Error: fseek file %s %04X\n", pszFilename, PEINDEX_POSITION);
		fclose(fPEFile);
		return -1;
	}

	if (fread(&uiPEHEADERIndex, sizeof(uiPEHEADERIndex), 1, fPEFile) != 1)
	{
		fprintf(stderr, "Error: reading file %s\n", pszFilename);
		fclose(fPEFile);
		return -1;
	}

	if (fseek(fPEFile, uiPEHEADERIndex + DLLCHARACTERISTICS_OFFSET, 0) != 0)
	{
		fprintf(stderr, "Error: fseek file %s %04X\n", pszFilename, uiPEHEADERIndex + DLLCHARACTERISTICS_OFFSET);
		fclose(fPEFile);
		return -1;
	}

	if (fread(&wDLLCHARACTERISTICS, sizeof(wDLLCHARACTERISTICS), 1, fPEFile) != 1)
	{
		fprintf(stderr, "Error: reading file %s\n", pszFilename);
		fclose(fPEFile);
		return -1;
	}

	printf("Original DLLCHARACTERISTICS = 0x%04X\n", wDLLCHARACTERISTICS);
	DisplayFlags(wDLLCHARACTERISTICS);

	if (2 == argc)
	{
		fclose(fPEFile);
		return 0;
	}

	for (iIter = 1; iIter < argc - 1; iIter++)
		if (!strcmp(argv[iIter], "+d"))
			wDLLCHARACTERISTICS |= 0x40;
		else if (!strcmp(argv[iIter], "-d"))
			wDLLCHARACTERISTICS &= 0xFFFF ^ 0x40;
		else if (!strcmp(argv[iIter], "+n"))
			wDLLCHARACTERISTICS |= 0x100;
		else if (!strcmp(argv[iIter], "-n"))
			wDLLCHARACTERISTICS &= 0xFFFF ^ 0x100;
		else if (!strcmp(argv[iIter], "+f"))
			wDLLCHARACTERISTICS |= 0x80;
		else if (!strcmp(argv[iIter], "-f"))
			wDLLCHARACTERISTICS &= 0xFFFF ^ 0x80;
		else
			printf("Error: unknown option %s\n", argv[iIter]);

	if (fseek(fPEFile, uiPEHEADERIndex + DLLCHARACTERISTICS_OFFSET, 0) != 0)
	{
		fprintf(stderr, "Error: fseek file %s %04X\n", pszFilename, uiPEHEADERIndex + DLLCHARACTERISTICS_OFFSET);
		fclose(fPEFile);
		return -1;
	}

	if (fwrite(&wDLLCHARACTERISTICS, sizeof(wDLLCHARACTERISTICS), 1, fPEFile) != 1)
	{
		fprintf(stderr, "Error: writing file %s\n", pszFilename);
		fclose(fPEFile);
		return -1;
	}

	printf("Updated  DLLCHARACTERISTICS = 0x%04X\n", wDLLCHARACTERISTICS);
	DisplayFlags(wDLLCHARACTERISTICS);

	fclose(fPEFile);

	return 0;
}

#define PCRE2_CODE_UNIT_WIDTH 8

#include "pcre2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("usage: [%s] [input path]\n", argv[0]);
		return 0;
	}
	pcre2_code *re = NULL;
	pcre2_match_data *match_data = NULL;
	PCRE2_SIZE erroffset, *ovector;
	int errorcode;
	int rc;
	int num;
	char strTemp[255];

	FILE *fp = NULL;
	if (fopen_s(&fp, argv[1], "r") != 0)
	{
		printf("no file found\n");
		return 0;
	}

	fscanf_s(fp, "%d", &num);
	fgetc(fp);

	PCRE2_SPTR pattern1 = (PCRE2_SPTR)"(\\G[0][2][-]\\d{3,4}[-]\\d{4})\\Z|(\\G[0][3][1][-]\\d{3,4}[-]\\d{4}\\Z)|(\\G[0][1][0][-]\\d{3,4}[-]\\d{4}\\Z)|(\\G[0][1][6][-]\\d{3,4}[-]\\d{4}\\Z)|(\\G[0][1][9][-]\\d{3,4}[-]\\d{4}\\Z)"; // write regular expression here
	while (num--)
	{
		fgets(strTemp, sizeof(strTemp), fp);
		PCRE2_SPTR input = (PCRE2_SPTR)strTemp;

		re = pcre2_compile(pattern1, -1, 0, &errorcode, &erroffset, NULL);

		if (re == NULL)
		{
			PCRE2_UCHAR8 buffer[120];
			(void)pcre2_get_error_message(errorcode, buffer, 120);
			/* Handle error */
			return 0;
		}

		match_data = pcre2_match_data_create(20, NULL);
		rc = pcre2_match(re, input, -1, 0, 0, match_data, NULL);

		if (rc <= 0)
			printf("N\n");
		else
		{
			ovector = pcre2_get_ovector_pointer_8(match_data);
			printf("Y\n", (int)ovector[0]);
			int index = (int)ovector[0];
			int n = 0;
		}
		
	}

	fscanf_s(fp, "%d", &num);
	fgetc(fp);

	PCRE2_SPTR pattern2 = (PCRE2_SPTR)"\\G(\\d{1,2}|[1]\\d{2}|[2][0]\\d|[2][1]\\d|[2][2]\\d|[2][3]\\d|[2][4]\\d|[2][5][0]|[2][5][1]|[2][5][2]|[2][5][3]|[2][5][4]|[2][5][5])([.](\\d{1,2}|[1]\\d{2}|[2][0]\\d|[2][1]\\d|[2][2]\\d|[2][3]\\d|[2][4]\\d|[2][5][0]|[2][5][1]|[2][5][2]|[2][5][3]|[2][5][4]|[2][5][5])){3}\\s-\\s-\\s\\[([1-9]|[1]\\d{1}|[2]\\d{1}|30)\\/Apr\\/2018\\]\\s(\")GET\\s\\/admin\\sHTTP\\/1.1(\")\\s304\\s0\\s(\")-(\")\\s(\")Mozilla\\/5.0(\\s+)\\(Macintosh;\\sIntel\\sMac\\sOS\\sX\\s10_13_3\\)\\sAppleWebKit\\/537.36\\s\\(KHTML.\\slike(\\s+)Gecko\\)\\sChrome\\/65.0.3325.181\\sSafari\\/537.36(\")\\s(\")-(\")\\Z"; // write regular expression here
	while (num--)
	{
		fgets(strTemp, sizeof(strTemp), fp);
		PCRE2_SPTR input = (PCRE2_SPTR)strTemp;

		re = pcre2_compile(pattern2, -1, 0, &errorcode, &erroffset, NULL);

		if (re == NULL)
		{
			PCRE2_UCHAR8 buffer[120];
			(void)pcre2_get_error_message(errorcode, buffer, 120);
			/* Handle error */
			return 0;
		}

		match_data = pcre2_match_data_create(20, NULL);
		rc = pcre2_match(re, input, -1, 0, 0, match_data, NULL);

		if (rc <= 0)
			printf("N\n");
		else
		{
			ovector = pcre2_get_ovector_pointer_8(match_data);
			printf("Y\n", (int)ovector[0]);
			int index = (int)ovector[0];
			int n = 0;
		}

	}
	
	fscanf_s(fp, "%d", &num);
	fgetc(fp);

	PCRE2_SPTR pattern3 = (PCRE2_SPTR)"\\G424D([0-9]|[A-F]){32}50([0-9]|[A-F]){6}46([0-9]|[A-F]){50}\\Z"; // write regular expression here
	while (num--)
	{
		fgets(strTemp, sizeof(strTemp), fp);
		PCRE2_SPTR input = (PCRE2_SPTR)strTemp;

		re = pcre2_compile(pattern3, -1, 0, &errorcode, &erroffset, NULL);

		if (re == NULL)
		{
			PCRE2_UCHAR8 buffer[120];
			(void)pcre2_get_error_message(errorcode, buffer, 120);
			/* Handle error */
			return 0;
		}

		match_data = pcre2_match_data_create(20, NULL);
		rc = pcre2_match(re, input, -1, 0, 0, match_data, NULL);

		if (rc <= 0)
			printf("N\n");
		else
		{
			ovector = pcre2_get_ovector_pointer_8(match_data);
			printf("Y\n", (int)ovector[0]);
			int index = (int)ovector[0];
			int n = 0;
		}

	}
	
	fclose(fp);

	pcre2_match_data_free(match_data);
	pcre2_code_free(re);
}
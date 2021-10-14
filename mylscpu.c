#include "myheader.h"

int main(void){

	FILE *cpuInfoFp, *L1dInfoFp, *L1iInfoFp, *L2InfoFp, *L3InfoFp;
	int line_num=0;
	char buf[BUFFER_SIZE];
	char tmp[BUFFER_SIZE];
	int check;

	if((cpuInfoFp = fopen(CPUINFO, "r")) == NULL){	// /proc/cpuinfo fopen
		fprintf(stderr, "fopen error for %s\n", CPUINFO);
		exit(1);
	}

	memset(buf,'\0',BUFFER_SIZE);

	char *ptr;
	char AddressSize[BUFFER_SIZE] = "Address sizes:			";
	char VendorId[BUFFER_SIZE] = "Vendor ID:			";
	char ModelName[BUFFER_SIZE] ="Model name:			";
	char CpuSpeed[BUFFER_SIZE] = "CPU MHz:			";
	char Flags[BUFFER_SIZE] = "Flags:				";
	char L1d[BUFFER_SIZE] = "L1d cache:	  		 ";
	char L1i[BUFFER_SIZE] = "L1i cache:	 		 ";
	char L2[BUFFER_SIZE] = "L2 cache:	 		 ";
	char L3[BUFFER_SIZE] = "L3 cache:	 		 ";


	char *Address_buf[2],*Vendor_buf[2], *Model_buf[2], *Cpu_buf[2], *Flags_buf[2];
	char address_buf[BUFFER_SIZE],vendor_buf[BUFFER_SIZE], model_buf[BUFFER_SIZE], cpu_buf[BUFFER_SIZE], flags_buf[BUFFER_SIZE], l1d_buf[BUFFER_SIZE], l1i_buf[BUFFER_SIZE], l2_buf[BUFFER_SIZE], l3_buf[BUFFER_SIZE];

	char *token;


	while(!feof(cpuInfoFp)){
		ptr = fgets(buf,BUFFER_SIZE, cpuInfoFp); //한 줄씩 읽기

		if(strstr(buf,"vendor_id")!=NULL){ // buf에서 문자열 찾기
			token = strtok(buf, ":"); // :를 기준으로 문자열 나누기
			int i=0;
			while(token != NULL){
				Vendor_buf[i] = token;
				i++;
				token = strtok(NULL,":");
			}
			memcpy(vendor_buf,Vendor_buf[1],BUFFER_SIZE);
		}
		else if(strstr(buf,"model name")!=NULL){
			token = strtok(buf, ":");
			int i=0;
			while(token != NULL){
				Model_buf[i] = token;
				i++;
				token = strtok(NULL,":");
			}
			memcpy(model_buf,Model_buf[1],BUFFER_SIZE);

		}
		else if(strstr(buf,"cpu MHz")!=NULL){
			token = strtok(buf, ":");
			int i=0;
			while(token != NULL){
				Cpu_buf[i] = token;
				i++;
				token = strtok(NULL,":");
			}
			memcpy(cpu_buf,Cpu_buf[1],BUFFER_SIZE);

		}
		else if(strstr(buf, "flags")!=NULL){
			token = strtok(buf, ":");
			int i=0;
			while(token != NULL){
				Flags_buf[i] = token;
				i++;
				token = strtok(NULL,":");
			}
			memcpy(flags_buf,Flags_buf[1],BUFFER_SIZE);

		}
		else if(strstr(buf,"address sizes")!=NULL){
			token = strtok(buf,":");
			int i=0;
			while(token != NULL){
				Address_buf[i] = token;
				i++;
				token = strtok(NULL,":");
			}
			memcpy(address_buf,Address_buf[1], BUFFER_SIZE);
		}
	}

	strcat(VendorId,vendor_buf); // 문자열 이어붙이기
	strcat(ModelName,model_buf);
	strcat(CpuSpeed,cpu_buf);
	strcat(Flags,flags_buf);
	strcat(AddressSize,address_buf);

	if((L1dInfoFp = fopen(L1dINFO,"r")) == NULL){
		fprintf(stderr, "fopen error for %s\n", L1dINFO);
		exit(1);
	}

	if((L1iInfoFp = fopen(L1iINFO, "r")) == NULL){
		fprintf(stderr,"fopen error for %s\n", L1iINFO);
		exit(1);
	}

	if((L2InfoFp = fopen(L2INFO, "r")) == NULL){
		fprintf(stderr, "fopen error for %s\n", L2INFO);
		exit(1);
	}
	if((L3InfoFp = fopen(L3INFO, "r")) == NULL){
		fprintf(stderr, "fopen error for %s\n", L3INFO);
		exit(1);
	}

	fgets(l1d_buf,BUFFER_SIZE,L1dInfoFp);
	fgets(l1i_buf,BUFFER_SIZE,L1iInfoFp);
	fgets(l2_buf,BUFFER_SIZE,L2InfoFp);
	fgets(l3_buf,BUFFER_SIZE,L3InfoFp);

	strcat(L1d,l1d_buf);
	strcat(L1i,l1i_buf);
	strcat(L2,l2_buf);
	strcat(L3,l3_buf);

	printf("%s",AddressSize);
	printf("%s", VendorId);
	printf("%s", ModelName);
	printf("%s", CpuSpeed);

	printf("%s",L1d);
	printf("%s",L1i);
	printf("%s",L2);
	printf("%s",L3);

	printf("%s", Flags);

	fclose(L1dInfoFp);
	fclose(L1iInfoFp);
	fclose(L2InfoFp);
	fclose(L3InfoFp);
	fclose(cpuInfoFp);
	return 0;

}







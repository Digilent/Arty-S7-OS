
#include <configs/platform-auto.h>

#define CONFIG_SYS_BOOTM_LEN 0xF000000
//replace extra env settings with modified ones to allow QSPI auto-boot
#undef CONFIG_EXTRA_ENV_SETTINGS 
#define CONFIG_EXTRA_ENV_SETTINGS \
	SERIAL_MULTI \ 
	CONSOLE_ARG \ 
	TTYUL0 \ 
	"autoload=no\0" \ 
	"sdbootdev=0\0" \ 
	"clobstart=0x80000000\0" \ 
	"netstart=0x80000000\0" \ 
	"dtbnetstart=0x81e00000\0" \ 
	"bootcmd=sf probe 0; sf read 0x81000000 ${kernelstart} ${kernelsize}; bootm 0x81000000 \0"  "loadaddr=0x80000000\0" \ 
	"bootsize=0x80000\0" \ 
	"bootstart=0x180000\0" \ 
	"boot_img=u-boot-s.bin\0" \ 
	"install_boot=sf probe 0 && sf erase ${bootstart} ${bootsize} && " \ 
		"sf write ${clobstart} ${bootstart} ${filesize}\0" \ 
	"bootenvsize=0x20000\0" \ 
	"bootenvstart=0x200000\0" \ 
	"eraseenv=sf probe 0 && sf erase ${bootenvstart} ${bootenvsize}\0" \ 
	"jffs2_img=rootfs.jffs2\0" \ 
	"install_jffs2=sf probe 0 && sf erase ${jffs2start} ${jffs2size} && " \ 
		"sf write ${clobstart} ${jffs2start} ${filesize}\0" \ 
	"kernelsize=0xd00000\0" \ 
	"kernelstart=0x220000\0" \ 
	"kernel_img=image.ub\0" \ 
	"install_kernel=sf probe 0 && sf erase ${kernelstart} ${kernelsize} && " \ 
		"sf write ${clobstart} ${kernelstart} ${filesize}\0" \ 
	"cp_kernel2ram=sf probe 0 && sf read ${netstart} ${kernelstart} ${kernelsize}\0" \ 
	"dtb_img=system.dtb\0" \ 
	"fault=echo ${img} image size is greater than allocated place - partition ${img} is NOT UPDATED\0" \ 
	"test_crc=if imi ${clobstart}; then run test_img; else echo ${img} Bad CRC - ${img} is NOT UPDATED; fi\0" \ 
	"test_img=setenv var \"if test ${filesize} -gt ${psize}\\; then run fault\\; else run ${installcmd}\\; fi\"; run var; setenv var\0" \ 
	"default_bootcmd=bootcmd\0" \ 
""

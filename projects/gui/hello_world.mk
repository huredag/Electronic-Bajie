##
## Auto Generated makefile by CDK
## Do not modify this file, and any manual changes will be erased!!!   
##
## BuildSet
ProjectName            :=hello_world
ConfigurationName      :=BuildSet
WorkspacePath          :=./
ProjectPath            :=./
IntermediateDirectory  :=Obj
OutDir                 :=$(IntermediateDirectory)
User                   :=006106
Date                   :=26/06/2026
CDKPath                :=../../../../../../CDK
ToolchainPath          :=D:/sort/C-Sky/CDKRepo/Toolchain/XTGccElfNewlib/V2.6.1/R/
LinkerName             :=riscv64-unknown-elf-gcc
LinkerNameoption       :=
SIZE                   :=riscv64-unknown-elf-size
READELF                :=riscv64-unknown-elf-readelf
CHECKSUM               :=crc32
SharedObjectLinkerName :=
ObjectSuffix           :=.o
DependSuffix           :=.d
PreprocessSuffix       :=.i
DisassemSuffix         :=.asm
IHexSuffix             :=.ihex
BinSuffix              :=.bin
ExeSuffix              :=.elf
LibSuffix              :=.a
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
ElfInfoSwitch          :=-hlS
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
UnPreprocessorSwitch   :=-U
SourceSwitch           :=-c 
ObjdumpSwitch          :=-S
ObjcopySwitch          :=-O ihex
ObjcopyBinSwitch       :=-O binary
OutputFile             :=$(ProjectName)
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
PreprocessOnlyDisableLineSwitch   :=-P
ObjectsFileList        :=hello_world.txt
MakeDirCommand         :=mkdir
LinkOptions            :=   --specs=nosys.specs  -nostartfiles  -Wl,--gc-sections  -T../../boards/td1601_evb/v1.0/gcc_flash.ld  -mcpu=e906fd 
LinkOtherFlagsOption   :=  -nostartfiles -Wl,--gc-sections -lm  -Wl,-zmax-page-size=1024 -Wl,-Map=$(ProjectPath)/Lst/$(OutputFile).map 
IncludePackagePath     :=
IncludeCPath           :=$(IncludeSwitch)../../components/chips/chip_td1601/v1.0/include $(IncludeSwitch)../../components/chips/chip_td1601/v1.0/sys $(IncludeSwitch)../../components/console/v1.0/ $(IncludeSwitch)../../components/csi/v1.0/include $(IncludeSwitch)../../components/csi/v1.0/include/core $(IncludeSwitch)../../components/lvgl/. $(IncludeSwitch)../../components/lvgl/src $(IncludeSwitch)../../components/minilibc/v1.0/include $(IncludeSwitch)../../components/mm/v1.0/include $(IncludeSwitch)../../boards/td1601_evb/v1.0/include  $(IncludeSwitch)include $(IncludeSwitch)include/sys $(IncludeSwitch)src/littlefs/ $(IncludeSwitch)src/ $(IncludeSwitch)../../components/lvgl/  
IncludeAPath           :=$(IncludeSwitch)../../components/chips/chip_td1601/v1.0/include $(IncludeSwitch)../../components/chips/chip_td1601/v1.0/sys $(IncludeSwitch)../../components/console/v1.0/ $(IncludeSwitch)../../components/csi/v1.0/include $(IncludeSwitch)../../components/csi/v1.0/include/core $(IncludeSwitch)../../components/lvgl/. $(IncludeSwitch)../../components/lvgl/src $(IncludeSwitch)../../components/minilibc/v1.0/include $(IncludeSwitch)../../components/mm/v1.0/include $(IncludeSwitch)../../boards/td1601_evb/v1.0/include  $(IncludeSwitch)include $(IncludeSwitch)include/sys $(IncludeSwitch)src/littlefs/ $(IncludeSwitch)src/ $(IncludeSwitch)../../components/lvgl/  
Libs                   := -Wl,--whole-archive $(LibrarySwitch)chip_td1601 $(LibrarySwitch)console $(LibrarySwitch)csi $(LibrarySwitch)lvgl $(LibrarySwitch)minilibc $(LibrarySwitch)mm $(LibrarySwitch)td1601_evb  -Wl,--no-whole-archive $(LibrarySwitch)m  
ArLibs                 := 
PackagesLibPath        :=
LibPath                :=$(LibraryPathSwitch)Obj  $(PackagesLibPath) 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       :=riscv64-unknown-elf-ar rcu
CXX      :=riscv64-unknown-elf-g++
CC       :=riscv64-unknown-elf-gcc
AS       :=riscv64-unknown-elf-gcc
OBJDUMP  :=riscv64-unknown-elf-objdump
OBJCOPY  :=riscv64-unknown-elf-objcopy
CXXFLAGS := $(PreprocessorSwitch)USE_CHIP_TD1601 $(PreprocessorSwitch)USE_CONSOLE $(PreprocessorSwitch)USE_CSI $(PreprocessorSwitch)USE_LVGL $(PreprocessorSwitch)USE_MINILIBC $(PreprocessorSwitch)USE_MM $(PreprocessorSwitch)USE_TD1601_EVB   -Os -g  -Os -g $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=16384 $(PreprocessorSwitch)CONFIG_BENCHMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_COREMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_DHRY=1 $(PreprocessorSwitch)CONFIG_CHIP_TD1601=1 $(PreprocessorSwitch)CONFIG_CPU_E906FD=1 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1 $(PreprocessorSwitch)CONFIG_XIP=1   -mcpu=e906fd   -O0  -g -DLV_CONF_INCLUDE_SIMPLE 
CFLAGS   := $(PreprocessorSwitch)USE_CHIP_TD1601 $(PreprocessorSwitch)USE_CONSOLE $(PreprocessorSwitch)USE_CSI $(PreprocessorSwitch)USE_LVGL $(PreprocessorSwitch)USE_MINILIBC $(PreprocessorSwitch)USE_MM $(PreprocessorSwitch)USE_TD1601_EVB   -Wno-unused-function -O2 -g -nostdlib -Wpointer-arith -Wall -Wl,-EL -ffunction-sections -fdata-sections -fdata-sections -Os -g  $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=16384 $(PreprocessorSwitch)CONFIG_BENCHMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_COREMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_DHRY=1 $(PreprocessorSwitch)CONFIG_CHIP_TD1601=1 $(PreprocessorSwitch)CONFIG_CPU_E906FD=1 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1 $(PreprocessorSwitch)CONFIG_XIP=1   -mcpu=e906fd   -O0  -g -DLV_CONF_INCLUDE_SIMPLE 
ASFLAGS  := $(PreprocessorSwitch)USE_CHIP_TD1601 $(PreprocessorSwitch)USE_CONSOLE $(PreprocessorSwitch)USE_CSI $(PreprocessorSwitch)USE_LVGL $(PreprocessorSwitch)USE_MINILIBC $(PreprocessorSwitch)USE_MM $(PreprocessorSwitch)USE_TD1601_EVB    $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=16384 $(PreprocessorSwitch)CONFIG_BENCHMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_COREMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_DHRY=1 $(PreprocessorSwitch)CONFIG_CHIP_TD1601=1 $(PreprocessorSwitch)CONFIG_CPU_E906FD=1 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1 $(PreprocessorSwitch)CONFIG_XIP=1   -mcpu=e906fd    
PreprocessFlags  := $(PreprocessorSwitch)USE_CHIP_TD1601 $(PreprocessorSwitch)USE_CONSOLE $(PreprocessorSwitch)USE_CSI $(PreprocessorSwitch)USE_LVGL $(PreprocessorSwitch)USE_MINILIBC $(PreprocessorSwitch)USE_MM $(PreprocessorSwitch)USE_TD1601_EVB   -Wno-unused-function -O2 -g -nostdlib -Wpointer-arith -Wall -Wl,-EL -ffunction-sections -fdata-sections -fdata-sections -Os -g  $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=16384 $(PreprocessorSwitch)CONFIG_BENCHMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_COREMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_DHRY=1 $(PreprocessorSwitch)CONFIG_CHIP_TD1601=1 $(PreprocessorSwitch)CONFIG_CPU_E906FD=1 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1 $(PreprocessorSwitch)CONFIG_XIP=1   -mcpu=e906fd   -O0  -g -DLV_CONF_INCLUDE_SIMPLE 


Objects0=$(IntermediateDirectory)/chip_config$(ObjectSuffix) $(IntermediateDirectory)/src_CST816$(ObjectSuffix) $(IntermediateDirectory)/src_ST77916$(ObjectSuffix) $(IntermediateDirectory)/src_board_init$(ObjectSuffix) $(IntermediateDirectory)/src_gpio_toggle$(ObjectSuffix) $(IntermediateDirectory)/src_images$(ObjectSuffix) $(IntermediateDirectory)/src_lfs$(ObjectSuffix) $(IntermediateDirectory)/src_lfs_port$(ObjectSuffix) $(IntermediateDirectory)/src_lfs_test$(ObjectSuffix) $(IntermediateDirectory)/src_lfs_util$(ObjectSuffix) \
	$(IntermediateDirectory)/src_lv_port_disp$(ObjectSuffix) $(IntermediateDirectory)/src_lv_port_indev$(ObjectSuffix) $(IntermediateDirectory)/src_main$(ObjectSuffix) $(IntermediateDirectory)/src_screens$(ObjectSuffix) $(IntermediateDirectory)/src_styles$(ObjectSuffix) $(IntermediateDirectory)/src_ui_font_cn_14$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_fan_high_off_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_fan_level_down_off_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_kt_off_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_off_background_image$(ObjectSuffix) \
	$(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_on_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_off_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_on_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_off_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_on_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_off_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_on_background_image$(ObjectSuffix) $(IntermediateDirectory)/src_ui_image_popup_button_mode_set_back_background_image$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all
all: $(IntermediateDirectory)/$(OutputFile)

$(IntermediateDirectory)/$(OutputFile):  $(Objects) Always_Link 
	$(LinkerName) $(OutputSwitch) $(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) $(LinkerNameoption) -Wl,-Map=$(ProjectPath)/Lst/$(OutputFile).map  @$(ObjectsFileList)  $(LinkOptions) $(LibPath) $(Libs) $(LinkOtherFlagsOption)
	-@mv $(ProjectPath)/Lst/$(OutputFile).map $(ProjectPath)/Lst/$(OutputFile).temp && $(READELF) $(ElfInfoSwitch) $(ProjectPath)/Obj/$(OutputFile)$(ExeSuffix) > $(ProjectPath)/Lst/$(OutputFile).map && echo ====================================================================== >> $(ProjectPath)/Lst/$(OutputFile).map && cat $(ProjectPath)/Lst/$(OutputFile).temp >> $(ProjectPath)/Lst/$(OutputFile).map && rm -rf $(ProjectPath)/Lst/$(OutputFile).temp
	$(OBJCOPY) $(ObjcopySwitch) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix)  $(ProjectPath)/Obj/$(OutputFile)$(IHexSuffix) 
	$(OBJDUMP) $(ObjdumpSwitch) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix)  > $(ProjectPath)/Lst/$(OutputFile)$(DisassemSuffix) 
	@echo size of target:
	@$(SIZE) $(ProjectPath)$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) 
	@echo -n checksum value of target:  
	@$(CHECKSUM) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) 
	@hello_world.modify.bat $(IntermediateDirectory) $(OutputFile)$(ExeSuffix) 

Always_Link:


##
## Objects
##
$(IntermediateDirectory)/chip_config$(ObjectSuffix): chip_config.c  
	$(CC) $(SourceSwitch) chip_config.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/chip_config$(ObjectSuffix) -MF$(IntermediateDirectory)/chip_config$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/chip_config$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/chip_config$(PreprocessSuffix): chip_config.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/chip_config$(PreprocessSuffix) chip_config.c

$(IntermediateDirectory)/src_CST816$(ObjectSuffix): src/CST816.c  
	$(CC) $(SourceSwitch) src/CST816.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_CST816$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CST816$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_CST816$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_CST816$(PreprocessSuffix): src/CST816.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_CST816$(PreprocessSuffix) src/CST816.c

$(IntermediateDirectory)/src_ST77916$(ObjectSuffix): src/ST77916.c  
	$(CC) $(SourceSwitch) src/ST77916.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ST77916$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ST77916$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ST77916$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ST77916$(PreprocessSuffix): src/ST77916.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ST77916$(PreprocessSuffix) src/ST77916.c

$(IntermediateDirectory)/src_board_init$(ObjectSuffix): src/board_init.c  
	$(CC) $(SourceSwitch) src/board_init.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_board_init$(ObjectSuffix) -MF$(IntermediateDirectory)/src_board_init$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_board_init$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_board_init$(PreprocessSuffix): src/board_init.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_board_init$(PreprocessSuffix) src/board_init.c

$(IntermediateDirectory)/src_gpio_toggle$(ObjectSuffix): src/gpio_toggle.c  
	$(CC) $(SourceSwitch) src/gpio_toggle.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_gpio_toggle$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gpio_toggle$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_gpio_toggle$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_gpio_toggle$(PreprocessSuffix): src/gpio_toggle.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_gpio_toggle$(PreprocessSuffix) src/gpio_toggle.c

$(IntermediateDirectory)/src_images$(ObjectSuffix): src/images.c  
	$(CC) $(SourceSwitch) src/images.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_images$(ObjectSuffix) -MF$(IntermediateDirectory)/src_images$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_images$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_images$(PreprocessSuffix): src/images.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_images$(PreprocessSuffix) src/images.c

$(IntermediateDirectory)/src_lfs$(ObjectSuffix): src/lfs.c  
	$(CC) $(SourceSwitch) src/lfs.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_lfs$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lfs$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_lfs$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_lfs$(PreprocessSuffix): src/lfs.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_lfs$(PreprocessSuffix) src/lfs.c

$(IntermediateDirectory)/src_lfs_port$(ObjectSuffix): src/lfs_port.c  
	$(CC) $(SourceSwitch) src/lfs_port.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_lfs_port$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lfs_port$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_lfs_port$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_lfs_port$(PreprocessSuffix): src/lfs_port.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_lfs_port$(PreprocessSuffix) src/lfs_port.c

$(IntermediateDirectory)/src_lfs_test$(ObjectSuffix): src/lfs_test.c  
	$(CC) $(SourceSwitch) src/lfs_test.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_lfs_test$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lfs_test$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_lfs_test$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_lfs_test$(PreprocessSuffix): src/lfs_test.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_lfs_test$(PreprocessSuffix) src/lfs_test.c

$(IntermediateDirectory)/src_lfs_util$(ObjectSuffix): src/lfs_util.c  
	$(CC) $(SourceSwitch) src/lfs_util.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_lfs_util$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lfs_util$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_lfs_util$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_lfs_util$(PreprocessSuffix): src/lfs_util.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_lfs_util$(PreprocessSuffix) src/lfs_util.c

$(IntermediateDirectory)/src_lv_port_disp$(ObjectSuffix): src/lv_port_disp.c  
	$(CC) $(SourceSwitch) src/lv_port_disp.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_lv_port_disp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lv_port_disp$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_lv_port_disp$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_lv_port_disp$(PreprocessSuffix): src/lv_port_disp.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_lv_port_disp$(PreprocessSuffix) src/lv_port_disp.c

$(IntermediateDirectory)/src_lv_port_indev$(ObjectSuffix): src/lv_port_indev.c  
	$(CC) $(SourceSwitch) src/lv_port_indev.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_lv_port_indev$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lv_port_indev$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_lv_port_indev$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_lv_port_indev$(PreprocessSuffix): src/lv_port_indev.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_lv_port_indev$(PreprocessSuffix) src/lv_port_indev.c

$(IntermediateDirectory)/src_main$(ObjectSuffix): src/main.c  
	$(CC) $(SourceSwitch) src/main.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_main$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_main$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_main$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_main$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/src_screens$(ObjectSuffix): src/screens.c  
	$(CC) $(SourceSwitch) src/screens.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_screens$(ObjectSuffix) -MF$(IntermediateDirectory)/src_screens$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_screens$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_screens$(PreprocessSuffix): src/screens.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_screens$(PreprocessSuffix) src/screens.c

$(IntermediateDirectory)/src_styles$(ObjectSuffix): src/styles.c  
	$(CC) $(SourceSwitch) src/styles.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_styles$(ObjectSuffix) -MF$(IntermediateDirectory)/src_styles$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_styles$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_styles$(PreprocessSuffix): src/styles.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_styles$(PreprocessSuffix) src/styles.c

$(IntermediateDirectory)/src_ui_font_cn_14$(ObjectSuffix): src/ui_font_cn_14.c  
	$(CC) $(SourceSwitch) src/ui_font_cn_14.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_font_cn_14$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_font_cn_14$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_font_cn_14$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_font_cn_14$(PreprocessSuffix): src/ui_font_cn_14.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_font_cn_14$(PreprocessSuffix) src/ui_font_cn_14.c

$(IntermediateDirectory)/src_ui_image_popup_button_fan_high_off_background_image$(ObjectSuffix): src/ui_image_popup_button_fan_high_off_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_fan_high_off_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_fan_high_off_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_fan_high_off_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_fan_high_off_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_fan_high_off_background_image$(PreprocessSuffix): src/ui_image_popup_button_fan_high_off_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_fan_high_off_background_image$(PreprocessSuffix) src/ui_image_popup_button_fan_high_off_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_fan_level_down_off_background_image$(ObjectSuffix): src/ui_image_popup_button_fan_level_down_off_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_fan_level_down_off_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_fan_level_down_off_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_fan_level_down_off_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_fan_level_down_off_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_fan_level_down_off_background_image$(PreprocessSuffix): src/ui_image_popup_button_fan_level_down_off_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_fan_level_down_off_background_image$(PreprocessSuffix) src/ui_image_popup_button_fan_level_down_off_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_kt_off_background_image$(ObjectSuffix): src/ui_image_popup_button_kt_off_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_kt_off_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_kt_off_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_kt_off_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_kt_off_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_kt_off_background_image$(PreprocessSuffix): src/ui_image_popup_button_kt_off_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_kt_off_background_image$(PreprocessSuffix) src/ui_image_popup_button_kt_off_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_off_background_image$(ObjectSuffix): src/ui_image_popup_button_mode_cold_off_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_mode_cold_off_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_off_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_off_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_off_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_mode_cold_off_background_image$(PreprocessSuffix): src/ui_image_popup_button_mode_cold_off_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_mode_cold_off_background_image$(PreprocessSuffix) src/ui_image_popup_button_mode_cold_off_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_on_background_image$(ObjectSuffix): src/ui_image_popup_button_mode_cold_on_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_mode_cold_on_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_on_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_on_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_mode_cold_on_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_mode_cold_on_background_image$(PreprocessSuffix): src/ui_image_popup_button_mode_cold_on_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_mode_cold_on_background_image$(PreprocessSuffix) src/ui_image_popup_button_mode_cold_on_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_off_background_image$(ObjectSuffix): src/ui_image_popup_button_mode_flash_off_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_mode_flash_off_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_off_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_off_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_off_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_mode_flash_off_background_image$(PreprocessSuffix): src/ui_image_popup_button_mode_flash_off_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_mode_flash_off_background_image$(PreprocessSuffix) src/ui_image_popup_button_mode_flash_off_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_on_background_image$(ObjectSuffix): src/ui_image_popup_button_mode_flash_on_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_mode_flash_on_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_on_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_on_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_mode_flash_on_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_mode_flash_on_background_image$(PreprocessSuffix): src/ui_image_popup_button_mode_flash_on_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_mode_flash_on_background_image$(PreprocessSuffix) src/ui_image_popup_button_mode_flash_on_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_off_background_image$(ObjectSuffix): src/ui_image_popup_button_mode_hot_off_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_mode_hot_off_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_off_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_off_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_off_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_mode_hot_off_background_image$(PreprocessSuffix): src/ui_image_popup_button_mode_hot_off_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_mode_hot_off_background_image$(PreprocessSuffix) src/ui_image_popup_button_mode_hot_off_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_on_background_image$(ObjectSuffix): src/ui_image_popup_button_mode_hot_on_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_mode_hot_on_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_on_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_on_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_mode_hot_on_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_mode_hot_on_background_image$(PreprocessSuffix): src/ui_image_popup_button_mode_hot_on_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_mode_hot_on_background_image$(PreprocessSuffix) src/ui_image_popup_button_mode_hot_on_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_off_background_image$(ObjectSuffix): src/ui_image_popup_button_mode_hum_off_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_mode_hum_off_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_off_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_off_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_off_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_mode_hum_off_background_image$(PreprocessSuffix): src/ui_image_popup_button_mode_hum_off_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_mode_hum_off_background_image$(PreprocessSuffix) src/ui_image_popup_button_mode_hum_off_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_on_background_image$(ObjectSuffix): src/ui_image_popup_button_mode_hum_on_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_mode_hum_on_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_on_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_on_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_mode_hum_on_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_mode_hum_on_background_image$(PreprocessSuffix): src/ui_image_popup_button_mode_hum_on_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_mode_hum_on_background_image$(PreprocessSuffix) src/ui_image_popup_button_mode_hum_on_background_image.c

$(IntermediateDirectory)/src_ui_image_popup_button_mode_set_back_background_image$(ObjectSuffix): src/ui_image_popup_button_mode_set_back_background_image.c  
	$(CC) $(SourceSwitch) src/ui_image_popup_button_mode_set_back_background_image.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/src_ui_image_popup_button_mode_set_back_background_image$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ui_image_popup_button_mode_set_back_background_image$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/src_ui_image_popup_button_mode_set_back_background_image$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/src_ui_image_popup_button_mode_set_back_background_image$(PreprocessSuffix): src/ui_image_popup_button_mode_set_back_background_image.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/src_ui_image_popup_button_mode_set_back_background_image$(PreprocessSuffix) src/ui_image_popup_button_mode_set_back_background_image.c


-include $(IntermediateDirectory)/*$(DependSuffix)

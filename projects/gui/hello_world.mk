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
Date                   :=24/06/2026
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
IncludeCPath           :=$(IncludeSwitch)../../components/chips/chip_td1601/v1.0/include $(IncludeSwitch)../../components/chips/chip_td1601/v1.0/sys $(IncludeSwitch)../../components/console/v1.0/ $(IncludeSwitch)../../components/csi/v1.0/include $(IncludeSwitch)../../components/csi/v1.0/include/core $(IncludeSwitch)../../components/lvgl/. $(IncludeSwitch)../../components/lvgl/src $(IncludeSwitch)../../components/minilibc/v1.0/include $(IncludeSwitch)../../components/mm/v1.0/include $(IncludeSwitch)../../boards/td1601_evb/v1.0/include  $(IncludeSwitch)include $(IncludeSwitch)include/sys $(IncludeSwitch)../../components/lvgl/  
IncludeAPath           :=$(IncludeSwitch)../../components/chips/chip_td1601/v1.0/include $(IncludeSwitch)../../components/chips/chip_td1601/v1.0/sys $(IncludeSwitch)../../components/console/v1.0/ $(IncludeSwitch)../../components/csi/v1.0/include $(IncludeSwitch)../../components/csi/v1.0/include/core $(IncludeSwitch)../../components/lvgl/. $(IncludeSwitch)../../components/lvgl/src $(IncludeSwitch)../../components/minilibc/v1.0/include $(IncludeSwitch)../../components/mm/v1.0/include $(IncludeSwitch)../../boards/td1601_evb/v1.0/include  $(IncludeSwitch)include $(IncludeSwitch)include/sys $(IncludeSwitch)../../components/lvgl/  
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
CXXFLAGS := $(PreprocessorSwitch)USE_CHIP_TD1601 $(PreprocessorSwitch)USE_CONSOLE $(PreprocessorSwitch)USE_CSI $(PreprocessorSwitch)USE_LVGL $(PreprocessorSwitch)USE_MINILIBC $(PreprocessorSwitch)USE_MM $(PreprocessorSwitch)USE_TD1601_EVB   -Os -g  -Os -g $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=4096 $(PreprocessorSwitch)CONFIG_BENCHMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_COREMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_DHRY=1 $(PreprocessorSwitch)CONFIG_CHIP_TD1601=1 $(PreprocessorSwitch)CONFIG_CPU_E906FD=1 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1 $(PreprocessorSwitch)CONFIG_XIP=1   -mcpu=e906fd   -Os  -g -DLV_CONF_INCLUDE_SIMPLE 
CFLAGS   := $(PreprocessorSwitch)USE_CHIP_TD1601 $(PreprocessorSwitch)USE_CONSOLE $(PreprocessorSwitch)USE_CSI $(PreprocessorSwitch)USE_LVGL $(PreprocessorSwitch)USE_MINILIBC $(PreprocessorSwitch)USE_MM $(PreprocessorSwitch)USE_TD1601_EVB   -Wno-unused-function -O2 -g -nostdlib -Wpointer-arith -Wall -Wl,-EL -ffunction-sections -fdata-sections -fdata-sections -Os -g  $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=4096 $(PreprocessorSwitch)CONFIG_BENCHMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_COREMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_DHRY=1 $(PreprocessorSwitch)CONFIG_CHIP_TD1601=1 $(PreprocessorSwitch)CONFIG_CPU_E906FD=1 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1 $(PreprocessorSwitch)CONFIG_XIP=1   -mcpu=e906fd   -Os  -g -DLV_CONF_INCLUDE_SIMPLE 
ASFLAGS  := $(PreprocessorSwitch)USE_CHIP_TD1601 $(PreprocessorSwitch)USE_CONSOLE $(PreprocessorSwitch)USE_CSI $(PreprocessorSwitch)USE_LVGL $(PreprocessorSwitch)USE_MINILIBC $(PreprocessorSwitch)USE_MM $(PreprocessorSwitch)USE_TD1601_EVB    $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=4096 $(PreprocessorSwitch)CONFIG_BENCHMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_COREMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_DHRY=1 $(PreprocessorSwitch)CONFIG_CHIP_TD1601=1 $(PreprocessorSwitch)CONFIG_CPU_E906FD=1 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1 $(PreprocessorSwitch)CONFIG_XIP=1   -mcpu=e906fd    
PreprocessFlags  := $(PreprocessorSwitch)USE_CHIP_TD1601 $(PreprocessorSwitch)USE_CONSOLE $(PreprocessorSwitch)USE_CSI $(PreprocessorSwitch)USE_LVGL $(PreprocessorSwitch)USE_MINILIBC $(PreprocessorSwitch)USE_MM $(PreprocessorSwitch)USE_TD1601_EVB   -Wno-unused-function -O2 -g -nostdlib -Wpointer-arith -Wall -Wl,-EL -ffunction-sections -fdata-sections -fdata-sections -Os -g  $(PreprocessorSwitch)CONFIG_ARCH_INTERRUPTSTACK=4096 $(PreprocessorSwitch)CONFIG_BENCHMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_COREMARK=1 $(PreprocessorSwitch)CONFIG_BENCHMARK_DHRY=1 $(PreprocessorSwitch)CONFIG_CHIP_TD1601=1 $(PreprocessorSwitch)CONFIG_CPU_E906FD=1 $(PreprocessorSwitch)CONFIG_DEBUG_MODE=1 $(PreprocessorSwitch)CONFIG_KERNEL_NONE=1 $(PreprocessorSwitch)CONFIG_SUPPORT_TSPEND=1 $(PreprocessorSwitch)CONFIG_XIP=1   -mcpu=e906fd   -Os  -g -DLV_CONF_INCLUDE_SIMPLE 


Objects0=$(IntermediateDirectory)/chip_config$(ObjectSuffix) $(IntermediateDirectory)/src_CST816$(ObjectSuffix) $(IntermediateDirectory)/src_ST77916$(ObjectSuffix) $(IntermediateDirectory)/src_board_init$(ObjectSuffix) $(IntermediateDirectory)/src_gpio_toggle$(ObjectSuffix) $(IntermediateDirectory)/src_lv_port_disp$(ObjectSuffix) $(IntermediateDirectory)/src_lv_port_indev$(ObjectSuffix) $(IntermediateDirectory)/src_main$(ObjectSuffix) 



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


-include $(IntermediateDirectory)/*$(DependSuffix)

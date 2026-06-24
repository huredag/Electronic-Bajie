.PHONY: clean All Project_Title Project_PreBuild chip_td1601 console csi lvgl minilibc mm td1601_evb Project_Build Project_PostBuild

All: Project_Title Project_PreBuild chip_td1601 console csi lvgl minilibc mm td1601_evb Project_Build Project_PostBuild

Project_Title:
	@echo "----------Building project:[ hello_world - BuildSet ]----------"

Project_PreBuild:
	@echo Executing Pre Build commands ...
	@export BOARD_PATH="D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/boards/td1601_evb/v1.0" CDKPath="D:/sort/C-Sky/CDK" CDK_VERSION="V2.22.0" CHIP_PATH="D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/components/chips/chip_td1601/v1.0" ProjectName="hello_world" ProjectPath="D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/projects/gui/" SOLUTION_PATH="D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/projects/gui/" chip_td1601="V1.0.0" console="V1.0.0" csi="V1.0.0" lvgl="V8.3.11" minilibc="V1.0.0" mm="V1.0.0" td1601_evb="V1.0.0" && "D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/projects/gui/utilities/pre_build.sh"
	@echo Done

chip_td1601:
	@make -r -f Obj/BuildSet/Packages/chip_td1601/V1.0.0/Makefile -j 16 -C  ./ 

console:
	@make -r -f Obj/BuildSet/Packages/console/V1.0.0/Makefile -j 16 -C  ./ 

csi:
	@make -r -f Obj/BuildSet/Packages/csi/V1.0.0/Makefile -j 16 -C  ./ 

lvgl:
	@make -r -f Obj/BuildSet/Packages/lvgl/V8.3.11/Makefile -j 16 -C  ./ 

minilibc:
	@make -r -f Obj/BuildSet/Packages/minilibc/V1.0.0/Makefile -j 16 -C  ./ 

mm:
	@make -r -f Obj/BuildSet/Packages/mm/V1.0.0/Makefile -j 16 -C  ./ 

td1601_evb:
	@make -r -f Obj/BuildSet/Packages/td1601_evb/V1.0.0/Makefile -j 16 -C  ./ 


Project_Build:
	@make -r -f hello_world.mk -j 16 -C  ./ 

Project_PostBuild:
	@echo Executing Post Build commands ...
	@export BOARD_PATH="D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/boards/td1601_evb/v1.0" CDKPath="D:/sort/C-Sky/CDK" CDK_VERSION="V2.22.0" CHIP_PATH="D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/components/chips/chip_td1601/v1.0" ProjectName="hello_world" ProjectPath="D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/projects/gui/" SOLUTION_PATH="D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/projects/gui/" chip_td1601="V1.0.0" console="V1.0.0" csi="V1.0.0" lvgl="V8.3.11" minilibc="V1.0.0" mm="V1.0.0" td1601_evb="V1.0.0" && "D:/sort/C-Sky/CDK/CSKY/PACK/td1601-lierda/projects/gui/utilities/aft_build.sh"
	@echo Done


clean:
	@echo "----------Cleaning project:[ hello_world - BuildSet ]----------"


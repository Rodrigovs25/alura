##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Forca
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/home/rvs/alura/linguagem_c++/curso_2/Forca
ProjectPath            :=/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Forca
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=RVS
Date                   :=17/01/24
CodeLitePath           :=/home/rvs/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/home/rvs/alura/linguagem_c++/curso_2/Forca/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/adiciona_palavra.cpp$(ObjectSuffix) $(IntermediateDirectory)/chuta.cpp$(ObjectSuffix) $(IntermediateDirectory)/imprime_cabecalho.cpp$(ObjectSuffix) $(IntermediateDirectory)/imprime_palavra.cpp$(ObjectSuffix) $(IntermediateDirectory)/nao_enforcou.cpp$(ObjectSuffix) $(IntermediateDirectory)/le_arquivo.cpp$(ObjectSuffix) $(IntermediateDirectory)/salva_arquivo.cpp$(ObjectSuffix) $(IntermediateDirectory)/nao_acertou.cpp$(ObjectSuffix) $(IntermediateDirectory)/imprime_erros.cpp$(ObjectSuffix) $(IntermediateDirectory)/Forca.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/sorteia_palavra.cpp$(ObjectSuffix) $(IntermediateDirectory)/letra_existe.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/adiciona_palavra.cpp$(ObjectSuffix): adiciona_palavra.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/adiciona_palavra.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/adiciona_palavra.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/adiciona_palavra.cpp$(PreprocessSuffix): adiciona_palavra.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/adiciona_palavra.cpp$(PreprocessSuffix) adiciona_palavra.cpp

$(IntermediateDirectory)/chuta.cpp$(ObjectSuffix): chuta.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/chuta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/chuta.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/chuta.cpp$(PreprocessSuffix): chuta.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/chuta.cpp$(PreprocessSuffix) chuta.cpp

$(IntermediateDirectory)/imprime_cabecalho.cpp$(ObjectSuffix): imprime_cabecalho.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/imprime_cabecalho.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imprime_cabecalho.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imprime_cabecalho.cpp$(PreprocessSuffix): imprime_cabecalho.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imprime_cabecalho.cpp$(PreprocessSuffix) imprime_cabecalho.cpp

$(IntermediateDirectory)/imprime_palavra.cpp$(ObjectSuffix): imprime_palavra.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/imprime_palavra.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imprime_palavra.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imprime_palavra.cpp$(PreprocessSuffix): imprime_palavra.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imprime_palavra.cpp$(PreprocessSuffix) imprime_palavra.cpp

$(IntermediateDirectory)/nao_enforcou.cpp$(ObjectSuffix): nao_enforcou.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/nao_enforcou.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nao_enforcou.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nao_enforcou.cpp$(PreprocessSuffix): nao_enforcou.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nao_enforcou.cpp$(PreprocessSuffix) nao_enforcou.cpp

$(IntermediateDirectory)/le_arquivo.cpp$(ObjectSuffix): le_arquivo.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/le_arquivo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/le_arquivo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/le_arquivo.cpp$(PreprocessSuffix): le_arquivo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/le_arquivo.cpp$(PreprocessSuffix) le_arquivo.cpp

$(IntermediateDirectory)/salva_arquivo.cpp$(ObjectSuffix): salva_arquivo.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/salva_arquivo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/salva_arquivo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/salva_arquivo.cpp$(PreprocessSuffix): salva_arquivo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/salva_arquivo.cpp$(PreprocessSuffix) salva_arquivo.cpp

$(IntermediateDirectory)/nao_acertou.cpp$(ObjectSuffix): nao_acertou.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/nao_acertou.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nao_acertou.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nao_acertou.cpp$(PreprocessSuffix): nao_acertou.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nao_acertou.cpp$(PreprocessSuffix) nao_acertou.cpp

$(IntermediateDirectory)/imprime_erros.cpp$(ObjectSuffix): imprime_erros.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/imprime_erros.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imprime_erros.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imprime_erros.cpp$(PreprocessSuffix): imprime_erros.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imprime_erros.cpp$(PreprocessSuffix) imprime_erros.cpp

$(IntermediateDirectory)/Forca.cpp$(ObjectSuffix): Forca.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/Forca.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Forca.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Forca.cpp$(PreprocessSuffix): Forca.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Forca.cpp$(PreprocessSuffix) Forca.cpp

$(IntermediateDirectory)/sorteia_palavra.cpp$(ObjectSuffix): sorteia_palavra.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/sorteia_palavra.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sorteia_palavra.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sorteia_palavra.cpp$(PreprocessSuffix): sorteia_palavra.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sorteia_palavra.cpp$(PreprocessSuffix) sorteia_palavra.cpp

$(IntermediateDirectory)/letra_existe.cpp$(ObjectSuffix): letra_existe.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rvs/alura/linguagem_c++/curso_2/Forca/Forca/letra_existe.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/letra_existe.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/letra_existe.cpp$(PreprocessSuffix): letra_existe.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/letra_existe.cpp$(PreprocessSuffix) letra_existe.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)



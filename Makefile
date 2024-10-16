include $(NVT_PRJCFG_MODEL)
include $(NVT_PRJCFG_MODEL_CFG)

#--------- ENVIRONMENT SETTING --------------------
$(info ************$(INCLUDE_DIR)********)
#
$(info ************$(NVT_PRJCFG_MODEL)********)

INCLUDES	= -I$(INCLUDE_DIR)
INCLUDES	+= -I$(INCLUDE_DIR)/../external/__install/include/opencv4
INCLUDES	+= -I$(INCLUDE_DIR)/../external/source/nvtinfo
WARNING		= -Wall -Wundef -Wsign-compare -Wno-missing-braces
COMPILE_OPTS	= $(INCLUDES) -I -O2 -fPIC -ffunction-sections -fdata-sections
CPPFLAGS	= 
CFLAGS		= $(PLATFORM_CFLAGS) $(PRJCFG_CFLAGS)
C_FLAGS		= $(COMPILE_OPTS) $(CPPFLAGS) $(CFLAGS) $(WARNING)

LIBRARY_DIR0	= $(INCLUDE_DIR)/../output
LIB_FFMPEG_DIR	= $(INCLUDE_DIR)/../external/__install/lib
LIB_FFMPEG	= -lavcodec -lavformat -lavutil -lswscale -lswresample
LIB_OPENCV	= -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio
LD_FLAGS	+= -L$(LIBRARY_DIR0) -L$(LIB_FFMPEG_DIR) $(LIB_FFMPEG) $(LIB_OPENCV) 
#--------- END OF ENVIRONMENT SETTING -------------

#-lopencv_superres  -lopencv_videostab  -lopencv_highgui 
DEP_LIBRARIES :=nvt@ext@lib@opencv

#--------- Compiling -------------------
BIN = koosvc-opencv
SRC = koosvc-opencv.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: all clean install

ifeq ("$(wildcard *.c *.cpp */*.c */*.cpp)","")
all:
	@echo ">>> Skip"
clean:
	@echo ">>> Skip"

else
all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LD_FLAGS)
	$(NM) -n $@ > $@.sym
	$(STRIP) $@
	$(OBJCOPY) -R .comment -R .note.ABI-tag -R .gnu.version $@

%.o: %.cpp
	$(CXX) $(C_FLAGS) -c $< -o $@

clean:
	rm -vf $(BIN) $(OBJ) $(BIN).sym *.o *.a *.so*
endif

install:
	@echo ">>>>>>>>>>>>>>>>>>> $@ >>>>>>>>>>>>>>>>>>>"
	@cp -avf $(BIN) $(ROOTFS_DIR)/rootfs/bin/

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
LD_FLAGS	= -L$(LIBRARY_DIR) -lopencv_shape -lopencv_stitching  -lopencv_dnn -lopencv_objdetect -lopencv_calib3d -lopencv_features2d -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core 
LD_FLAGS	+= -L$(LIBRARY_DIR0) -lnvtinfo
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

#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

# Add your Source files and include paths based on the platform
ifeq ($(PLATFORM),HOST)
	SOURCES =/home/ecee/course1/src/main.c \
		 /home/ecee/course1/src/ memory.c \
		/home/ecee/course1/src/ course1.c \
	       /home/ecee/course1/src/ data.c \
	       /home/ecee/course1/src/ stats.c \
       	       
	INCLUDES=-I/home/ecee/course1/include/common
else ifeq ($(PLATFORM),MSP432) 
	SOURCES =-I/home/ecee/course1/src
	INCLUDES =-I/home/ecee/course1/include/CMSIS \
		  -I/home/ecee/course1/include/common \
		  -I/home/ecee/course1/include/msp432
endif  



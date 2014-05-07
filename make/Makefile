
SYSROOT = /home/sofiane/bin/android-ndk-r9/platforms/android-18/arch-arm/
ANDROID_DEV = /home/sofiane/bin/android-ndk-r9/platforms/android-18/arch-arm/usr
CC = /home/sofiane/bin/android-ndk-r9/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc --sysroot=$(SYSROOT)
AR = /home/sofiane/bin/android-ndk-r9/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86_64/bin/arm-linux-androideabi-ar
CFLAGS = -D TSC_ANDROID -D TSC_LINUX -D LWIP_DEBUG -D TSC_UIP -D TSC_OPENSSL -D TSC_MONITOR -march=armv7-a -mandroid -I$(ANDROID_DEV)/include -B$(ANDROID_DEV)/lib -O3 -fomit-frame-pointer -Wall

all: libsub.so
	$(CC) test.c $(CLAGS) -L. -lsub -o b.out

additon.o : addition.c
	$(CC) -c $^ $(CLAGS) -o $@

subtract.o : subtract.c
	$(CC) -c -fPIC $^ $(CLAGS) -o $@

libadd.a : addition.o
	$(AR) rcs $@ $^

libsub.so : subtract.o libadd.a
	$(CC) -shared -Wl,-soname=$@,--whole-archive,-L.,-ladd,--no-whole-archive subtract.o $(CLAGS) -o $@

# gcc -Wl,-soname=libsub.so,-L.,-ladd -o libsub.so subtract.o

clean: 
	rm -rf *.o
	rm -rf *.so
	rm -rf *.a
	rm -rf *.out


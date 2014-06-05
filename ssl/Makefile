OBJS = common.o sclient.o client.o
IFLAGS = -I openssl/extlib/openssl-1.0.1g/include
LDFLAGS = -L openssl/extlib/openssl-1.0.1g/lib
all: $(OBJS)
	gcc -o sipclient $^ $(IFLAGS) $(LDFLAGS) -lssl

clean:
	rm -f $(OBJS)	

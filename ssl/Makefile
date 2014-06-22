OBJS = common.o sclient.o client.o
IFLAGS = -I openssl/extlib/openssl-1.0.1g/include/
LDFLAGS = -Lopenssl/extlib/openssl-1.0.1g

all: sipclient
.c.o:
	gcc -c -o $*.o $(IFLAGS) $(LDFLAGS) $< -lssl -lcrypto -lwsock32 -lWs2_32 -lwinmm -lgdi32 -lIphlpapi 
sipclient: $(OBJS)
	gcc -o sipclient $^ $(IFLAGS) $(LDFLAGS) -lcrypto -lssl -lcrypto -lwsock32 -lWs2_32 -lwinmm -lgdi32 -lIphlpapi 


clean:
	rm -f $(OBJS)	

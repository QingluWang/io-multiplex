CFLAGS=-Wall -g -lpthread
target=server.out
obj=server_main.o my_server.o my_tcp.o

$(target):$(obj)
	$(CC) $^ -o $@ $(CFLAGS)
server_main.o:server_main.c
	$(CC) -c $< -o $@ $(CFLAGS)
my_server.o:my_server.c
	$(CC) -c $< -o $@ $(CFLAGS)
my_tcp.o:../tcp/my_tcp.c
	$(CC) -c $< -o $@ $(CFLAGS)
clean:
	rm -rf $(obj) $(target)
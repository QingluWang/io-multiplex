CFLAGS=-Wall -g -lpthread
target=client.out
obj=client_main.o my_client.o my_tcp.o

$(target):$(obj)
	$(CC) $^ -o $@ $(CFLAGS)
client_main.o:client_main.c
	$(CC) -c $< -o $@ $(CFLAGS)
my_client.o:my_client.c my_client.h
	$(CC) -c $< -o $@ $(CFLAGS)
my_tcp.o:../tcp/my_tcp.c ../tcp/my_tcp.h
	$(CC) -c $< -o $@ $(CFLAGS)
clean:
	rm -rf $(obj) $(target)
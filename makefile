user_defined_signal: user_defined_signal_client user_defined_signal.c
	gcc -o user_defined_signal user_defined_signal.c

user_defined_signal_client: user_defined_signal_client.c
	gcc -o user_defined_signal_client user_defined_signal_client.c
	
.PHONY:clean
clean:
	-rm user_defined_signal user_defined_signal_client

.PHONY:run
run:
	./user_defined_signal

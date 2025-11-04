CC=gcc 
CFLAGs= -Wall -Wextra -Wpedantic -std=c99

app: src/main.c 
	$(CC) $(CFLAGs) $^ -o app
	
.PHONY: clean 
clean: 
	rm -f $(OBJECT_DIR) $(BIN_DIR) 
			
	

	

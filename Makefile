LIBS=-lcrypto -lssl

g++ -o small_letters_show $(LIBS) small_letters_show.cc
g++ -o full_show $(LIBS) full_show.cc
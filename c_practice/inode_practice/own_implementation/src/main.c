/**
 * file: inode_practice/own_implementation/src/main.c
 * author: Emilio L <escott15@calpoly.edu>
 * date: 2026-10-27
 *
 * little inode DT implementation
 */

#include <stdint.h>
#include <time.h>

/**
 * struct inode is our own specific implementation of inode,
 * using different unsigned int types to represent the values
 *
 * @param: uint64_t inode_number, this is the file i-node number /
 *         serial number to identify the inode
 * @param: uint32_t mode, modes / permissions, as well as declaring
 *		   what kind of file it is (dir, symlink, FIFO, etc)
 * @param: uint32_t owner_uid User ID of the owner of the inode/file
 * @param: uint32_t owner_gid, User Id of the group of the inode/file
 * @param: uint62_t size, size
 * @param:
 */
struct inode {
	 uint64_t inode_number;
    uint32_t mode;
    uint32_t owner_uid;
    uint32_t owner_gid;
    uint64_t size;
    uint32_t link_count;

    struct timespec access_time;
    struct timespec modification_time;
    struct timespec change_time;
};

int createinode()

/**
 * main(): entry point of program
 * @param: int argc, argument counter
 * @param: char *argv[] array of arguments
 */
int main(int argc, char *argv[]){

	return 0;
}


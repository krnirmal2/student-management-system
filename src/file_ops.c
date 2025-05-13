#include "file_ops.h"
#include <stdio.h>
#include <stdlib.h>

// Backup the student database
void backup_database() {
    FILE *src = fopen("data/DATABASE.DAT", "rb");
    FILE *dest = fopen("data/BACKUP.DAT", "wb");
    if (!src || !dest) {
        printf("Error opening files for backup.\n");
        if (src) fclose(src);
        if (dest) fclose(dest);
        return;
    }
    char buf[1024];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), src)) > 0) {
        fwrite(buf, 1, n, dest);
    }
    fclose(src);
    fclose(dest);
    printf("Backup completed successfully.\n");
}

// Show progress bar during backup
void progress() {
    // For text UI, just print a message
    printf("Progress: [##########] Done!\n");
}

// Exit the system safely
void exit_system() {
    printf("Exiting the system. Goodbye!\n");
    exit(0);
} 
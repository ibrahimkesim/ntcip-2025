#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATE_TIME_FORMAT "%Y-%m-%dT%H:%M:%S"

// Function to convert date string to epoch time
time_t convert_to_epoch(const char *date_string) {
    struct tm tm;
    char *ret;
    double milliseconds = 0;
    time_t epoch_time;

    // Initialize tm to zero
    memset(&tm, 0, sizeof(struct tm));

    // Parse the date string
    ret = strptime(date_string, DATE_TIME_FORMAT, &tm);
    if (ret == NULL) {
        fprintf(stderr, "Failed to parse date string\n");
        return -1;
    }

    // Handle milliseconds if present
    if (*ret == '.') {
        char ms_str[4] = {0}; // Buffer for milliseconds
        strncpy(ms_str, ret + 1, 3); // Copy up to 3 digits of milliseconds
        milliseconds = strtod(ms_str, NULL) / 1000.0;
    }

    // Convert parsed time to epoch time
    epoch_time = mktime(&tm);

    // Add milliseconds
    if (epoch_time != -1) {
        epoch_time += milliseconds;
    }

    return epoch_time;
}

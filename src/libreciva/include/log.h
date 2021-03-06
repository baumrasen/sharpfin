/* 
 * Sharpfin project
 * Copyright (C) by Steve Clarke and Ico Doornekamp
 * 2011-11-30 Philipp Schmidt
 *   Added to github 
 *
 * This file is part of the sharpfin project
 *  
 * This Library is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this source files. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef log_h
#define log_h
enum log_to {
	LOG_TO_STDERR = 1,
	LOG_TO_SYSLOG = 2,
};

enum log_level {
	LG_FTL,
	LG_ERR,
	LG_WRN,
	LG_INF,
	LG_DBG,
};

#define logf(level, args...) log_entry(level, __FUNCTION__, args )
void log_init(char *progname, enum log_to to, enum log_level level, int color);
void log_entry(enum log_level level, const char *func, char *fmt, ...)  __attribute__((format(printf, 3, 4)));
void log_hexdump(char *txt, unsigned char *data, int len);
#endif

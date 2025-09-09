#include <dirent.h> // 目录操作相关头文件，包含DIR、struct dirent等定义
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 字符串处理函数库
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#define BUFFER_SIZE 1024 // 缓冲区大小，用于文件内容的读写

int main() {
  DIR *dir;                 // 目录流指针，opendir函数的返回值
  struct dirent *entry;     // 目录项结构体指针，存储目录中每个文件的信息
  char dir_path[1024];      // 存储要查看的目录路径
  char src_path[1024];      // 存储源文件路径
  char dest_path[1024];     // 存储目标文件路径
  int fd_from, fd_to;       // 文件描述符，用于标识打开的文件
  ssize_t bytes_read;       // 每次读取的字节数，ssize_t是有符号的size_t
  char buffer[BUFFER_SIZE]; // 数据传输缓冲区，用于暂存读写的文件内容

  /*
   * 目录操作函数说明：opendir、readdir、closedir
   * 1. opendir函数
   *   - 功能：打开指定目录，返回目录流指针
   *   - 原型：DIR *opendir(const char *name);
   *   - 参数：name为要打开的目录路径
   *   - 返回值：成功返回DIR*指针，失败返回NULL并设置errno
   */
  printf("请输入要查看的目录路径：");
  scanf("%s", dir_path);

  dir = opendir(dir_path);
  if (dir == NULL) {
    perror("打开目录失败");
    exit(EXIT_FAILURE);
  }

  /*
   * 2. readdir函数
   *   - 功能：从目录流中读取一个目录项
   *   - 原型：struct dirent *readdir(DIR *dirp);
   *   - 参数：dirp为opendir返回的目录流指针
   *   - 返回值：成功返回struct dirent*指针，
   *             到达目录末尾或失败返回NULL
   *   - struct dirent关键成员：
   *       d_name: 文件名
   *       d_ino: 文件的inode号
   */
  printf("目录 %s 下的所有文件：\n", dir_path);
  while ((entry = readdir(dir)) != NULL) {
    // 跳过当前目录（.）和父目录（..）这两个特殊目录项
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    printf("%s\n", entry->d_name);
  }

  /*
   * 3. closedir函数
   *   - 功能：关闭目录流，释放资源
   *   - 原型：int closedir(DIR *dirp);
   *   - 参数：dirp为要关闭的目录流指针
   *   - 返回值：成功返回0，失败返回-1并设置errno
   *   - 注意：使用opendir打开的目录必须用closedir关闭，避免资源泄漏
   */
  if (closedir(dir) == -1) {
    perror("关闭目录失败");
    exit(EXIT_FAILURE);
  }

  // 获取用户输入的源文件和目标文件路径
  printf("\n请输入源文件的路径：");
  scanf("%s", src_path);

  printf("请输入目标文件的路径：");
  scanf("%s", dest_path);

  // 打开源文件（只读模式）
  fd_from = open(src_path, O_RDONLY);
  if (fd_from == -1) {
    perror("打开源文件失败");
    exit(EXIT_FAILURE);
  }

  /*
   * lseek函数说明
   *   - 功能：修改文件描述符的当前读写位置（偏移量）
   *   - 原型：off_t lseek(int fd, off_t offset, int whence);
   *   - 参数：
   *       fd: 文件描述符
   *       offset: 偏移量（正数向后，负数向前）
   *       whence: 参考位置：
   *           SEEK_SET: 从文件开头计算
   *           SEEK_CUR: 从当前位置计算
   *           SEEK_END: 从文件末尾计算
   *   - 返回值：成功返回新偏移量，失败返回-1并设置errno
   *   - 示例：获取文件大小
   *       off_t file_size = lseek(fd_from, 0, SEEK_END);
   *       注意：获取后通常需要将指针移回开头
   *       lseek(fd_from, 0, SEEK_SET);
   */

  /*
   * mkdir函数说明
   *   - 功能：创建新目录
   *   - 原型：int mkdir(const char *pathname, mode_t mode);
   *   - 参数：
   *       pathname: 要创建的目录路径
   *       mode: 目录权限（如S_IRWXU表示所有者读写执行权限）
   *   - 返回值：成功返回0，失败返回-1并设置errno
   *   - 注意：只能创建单级目录，创建多级目录需递归调用
   *   - 示例：mkdir("new_dir", S_IRWXU | S_IRGRP | S_IXGRP);
   */

  // 打开/创建目标文件（只写模式，存在则截断，设置权限）
  fd_to = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC,
               S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd_to == -1) {
    perror("打开或创建目标文件失败");
    close(fd_from); // 确保关闭已打开的源文件
    exit(EXIT_FAILURE);
  }

  // 循环读取源文件并写入目标文件
  while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
    if (write(fd_to, buffer, bytes_read) != bytes_read) {
      perror("写入目标文件失败");
      close(fd_from);
      close(fd_to);
      exit(EXIT_FAILURE);
    }
  }

  // 检查读取操作是否出错
  if (bytes_read == -1) {
    perror("读取源文件失败");
    close(fd_from);
    close(fd_to);
    exit(EXIT_FAILURE);
  }

  // 关闭源文件
  if (close(fd_from) == -1) {
    perror("关闭源文件失败");
    exit(EXIT_FAILURE);
  }

  // 关闭目标文件
  if (close(fd_to) == -1) {
    perror("关闭目标文件失败");
    exit(EXIT_FAILURE);
  }

  printf("文件复制成功：%s -> %s\n", src_path, dest_path);
  return 0;
}

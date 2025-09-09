#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024 // 定义缓冲区大小

int main(int argc, char *argv[]) {
  int fd_from, fd_to;       // 文件描述符
  ssize_t bytes_read;       // 读取的字节数
  char buffer[BUFFER_SIZE]; // 缓冲区

  // 检查命令行参数是否正确
  if (argc != 3) {
    fprintf(stderr, "用法: %s 源文件 目标文件\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // 打开源文件，只读模式
  fd_from = open(argv[1], O_RDONLY);
  if (fd_from == -1) {
    perror("打开源文件失败");
    exit(EXIT_FAILURE);
  }

  // 打开或创建目标文件，写入模式，如果文件存在则截断为0
  // 权限设置为所有者可读写，其他用户只读
  fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
               S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd_to == -1) {
    perror("打开或创建目标文件失败");
    close(fd_from); // 确保关闭已打开的文件
    exit(EXIT_FAILURE);
  }

  // 循环读取源文件内容并写入目标文件
  while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
    if (write(fd_to, buffer, bytes_read) != bytes_read) {
      perror("写入文件失败");
      close(fd_from);
      close(fd_to);
      exit(EXIT_FAILURE);
    }
  }

  // 检查读取操作是否出错
  if (bytes_read == -1) {
    perror("读取文件失败");
    close(fd_from);
    close(fd_to);
    exit(EXIT_FAILURE);
  }

  // 关闭文件描述符
  if (close(fd_from) == -1) {
    perror("关闭源文件失败");
    exit(EXIT_FAILURE);
  }

  if (close(fd_to) == -1) {
    perror("关闭目标文件失败");
    exit(EXIT_FAILURE);
  }

  printf("文件复制成功: %s -> %s\n", argv[1], argv[2]);
  return 0;
}

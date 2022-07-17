# Exceptio  
Фундамент для построения здания исключений, разных и сложных  
Нужно лишь подключить заголовочный файл (с ресурсами к нему)  
  
## class Exceptio  
Реализует простейшее исключение для блока `try-catch`, которое может в себя включать:  
- index (`int`), индекс, используемый для перечисления
- description(`const wchar_t*`, `const std::wstring&`), описание ошибки
- comment(`const wchar_t*`, `const std::wstring&`), комментарий, любой другой текст, позволяющий как-то что-то облегчить
  
Представлено несколько конструкторов, но каждый из них можно заменить полным, используя "заглушки"  
`INT_PLUG` и `STR_PLUG`, которые бы засчитывались как отсутсвующие параметры  
Функции `checking_<>_for_out` проверяют на соответствие полей класса каким-либо реальным  
параметрам, заглушки дают false.  
  
Подключаемый файл `exceptio.hpp`  
  
## class Assert
Реализует простейшую версию версию assert'a, основанную на вызове конструктора настоящего класса,  
вследствие чего вызывается исключение `Exceptio`. Необходимо нахожение внутри блока `try-catch`.  
  
Подключаемый файл `my_assert.hpp`  
  
# Компиляция с помощью CMake  
  
## Отдельно  
Создаём папку, в которой будем собирать проект, например, `build`.  
После:  
+ `cd .\build\`
+ `cmake ..`
+ `cmake --build .`
  
## С чем-либо  
Добавляем как минимум папки `/src` и `/include` и файл `CMakeLists.txt` в любую директорию  
После в заглавном файле CMakeLists добавляем эту директорию как подпроект  
Потом прилинковать библиотеку через её имя, например, так: `target_link_libraries( ${PROJECT} EXCEPTIO_CPP_LIBRARY )`  
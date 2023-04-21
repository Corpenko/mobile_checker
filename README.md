# Mobile Device Checker

>ENGLISH:
  Author: [Profile](https://pawn.wiki/index.php?/user/49636-21th-year/)
  Plans:
- [x] Create include
- [] Optimization include
- [] Create new functions

  Functions:
    1) SetDeviceType – Arguments: playerid, 0/1
    2) GetPlayerClient – Arguments: playerid
    3) IsAMobile – Arguments: playerid
  Enum structure:
    1) e_szClientID
    2) e_szAuthKey
    3) e_szClientName
  How write your hash?:
    1) Open Include
    2) Goto to line with text: "m_structure_authkeys"
    3) Down, than input Hash ID
    4) Than, input "," write your hash

>RUSSIAN:
  Автор: [Страница](https://pawn.wiki/index.php?/user/49636-21th-year/)
  Планы:
- [x] Создать инклуд
- [] Оптимизация
- [] Создание новых функций

  Функции:
    1) SetDeviceType – Аргументы: playerid, 0/1
    2) GetPlayerClient – Аргументы: playerid
    3) IsAMobile – Аргументы: playerid
  Enum структура:
    1) e_szClientID
    2) e_szAuthKey
    3) e_szClientName
    
  Как записать свой хеш?:
    1) Открываем инклуд
    2) Ищем строку m_structure_authkeys
    3) Спускаемся вниз массива, затем указываем ID вашего хеша в числовом порядке
    4) Открываем кавычки, указываем хеш
    5) Закрываем кавычки, ставим запятую, заново открывает пишем название клиента, закрываем кавычки

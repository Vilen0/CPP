# Программирование на языке высокого уровня (Python).
# Задание №4.3.6 Вариант 1
#
# Выполнил: Автандилян В.С.
# Группа: ПИН-б-о-21-1
# E-mail: v.avtandilyan@mail.ru

class Плеер:

    def __init__(self, name):
        if not isinstance(name, str):
            raise TypeError("Название должно быть строкой")

        self._name = name

    def run(self):
        print(f"Аудио {self._name} запущено\n")

    def stop(self):
        print(f"Аудио {self._name} остановлено\n")

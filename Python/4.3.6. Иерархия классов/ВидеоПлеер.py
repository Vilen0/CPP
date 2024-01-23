# Программирование на языке высокого уровня (Python).
# Задание №4.3.6 Вариант 1
#
# Выполнил: Автандилян В.С.
# Группа: ПИН-б-о-21-1
# E-mail: v.avtandilyan@mail.ru


from Плеер import Плеер

class ВидеоПлеер(Плеер):
    def __init__(self, name):
        if not isinstance(name, str):
            raise TypeError

        super().__init__(name)

    def run(self):
        super().run()

    def stop(self):
        super().stop()

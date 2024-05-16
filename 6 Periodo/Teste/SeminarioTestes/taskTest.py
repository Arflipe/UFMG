from taskManager import Task, TaskManager
from hypothesis import given, settings, strategies as st

# Estratégia para gerar tarefas
task_strategy = st.builds(Task, description=st.text(min_size=1), priority=st.integers(min_value=0, max_value=100))

@given(task_strategy)
def test_add_task(task):
  manager = TaskManager()
  manager.add_task(task)
  assert task in manager.tasks

@given(task_strategy)
def test_remove_task(task):
  manager = TaskManager()
  manager.add_task(task)
  manager.remove_task(task.description)
  assert task not in manager.tasks

@given(st.lists(task_strategy))
def test_get_tasks_sorted_by_priority(tasks):
  manager = TaskManager()
  for task in tasks:
      manager.add_task(task)
  sorted_tasks = manager.get_tasks_sorted_by_priority()
  priorities = [task.priority for task in sorted_tasks]
  assert priorities == sorted(priorities)

@given(st.lists(task_strategy))
@settings(max_examples=10)
def test_sorting_does_not_change_number_of_tasks(tasks):
  manager = TaskManager()
  for task in tasks:
      manager.add_task(task)
  sorted_tasks = manager.get_tasks_sorted_by_priority()
  assert len(tasks) == len(sorted_tasks)
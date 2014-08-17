# Information
Name: Topic
Description: Drupal feature module.

# Blueprint
* Topic
* Subject

## Topic
* Node: topic
* Fields:
    - body
    - field_topic_name: machine_name
* IA
    - [node:field_topic_name]

## Subject
* Node: subject
* Fields:
    - body
    - field_topic: entityreference
* IA
    - [node:field-topic:url:path]/[node:title]

# Insertion-Sort

1st layer loop: pointer **j** from 2 -> end

- make sure the Seq. **1** **to** **j-1** are **sorted**.
- let x = value @ j
- scan the **sorted** part from *j-1* to *1* (pointer *i*)
  - if **i**th > **x**, let **i+1**th = **i**th
  - push pointer ahead, i -> i-1
- let **i+1**th = x

Commit: update pointer **i+1** as the insert place. 

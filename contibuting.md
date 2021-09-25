
# Contributing to CP-Handbook

The goal is 100% coverage of the book. However, this is still an ongoing
endeavour. Therefore, you are welcome to jump in and help. You can add anything
from comments, documentation, test cases, print helpers, corrections and, of
course, any of the algorithms that are not currently covered.

---

## Reference guide


* Go to https://github.com/ThanasisMattas/cp-handbook and fork the project
* Clone the project to your computer: <br />

  ```git clone git@github.com:your-username/cp-handbook.git```

* Navigate to the cp-handbook folder and add the upstream repository: <br />

  ```git remote add upstream git@github.com:ThanasisMattas/cp-handbook.git```
* Pull the latest changes (and push them to your remote fork (origin), if you
  like): <br />

  ```git checkout master``` <br />
  ```git pull upstream master``` <br />
  ```git push```

* Create and checkout a new branch, for example: <br />

  ```git checkout -b add-ch7-coin-problem```

* Do your thing
* Push your changes to your fork: <br />

  ```git push origin add-ch7-coin-problem```

* Go to your fork at your GitHub profile and
  **click the green Pull Request button**
* For any subsequent commit on that branch, just push to your fork and the pull
  request will be updated automatically. In case that there is a conflict
  induced by your changes (because someone else made a change on the same
  files) you have to *rebase* your commits over the last commit: <br />

  ```git checkout master``` <br />
  ```git pull upstream master``` <br />
  ```git push``` <br />
  ```git checkout add-ch7-coin-problem``` <br />
  ```git rebase master``` <br />

  Resolve conflicts, if any. Follow the instructions
    (you may need to ```git rebase continue```). <br />

  ```git push -f origin add-ch7-coin-problem```

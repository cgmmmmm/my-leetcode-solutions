# Optimization via Proof by Induction

The cost function of splitting an integer `x` into two positive integers is:

$$
C(a,b)=a\times b
$$

where:

$$
a+b=x,\qquad a,b\in\mathbb{Z}^{+}
$$

We want to determine the minimum total cost of splitting an integer `n` into `n` ones.

## [1] Finding the Minimum Cost of an Individual Split

Given that:

$$
a+b=x
$$

We can express the cost as:

$$
C(a)=a(x-a)
$$

Since `a` and `b` must be positive integers, the minimum cost occurs when either `a=1` or `b=1`.

Therefore, the minimum cost of splitting any integer `x` is:

$$
\boxed{\operatorname{minCost}(x)=x-1}
$$

## [2] Formulating the Total Cost Function

Let `f(n)` represent the total cost of splitting an integer `n` into `n` ones.

If we repeatedly split one side into `1` and `x-1`, we obtain:

$$
f(n)=(n-1)+(n-2)+\cdots+2+1
$$

Therefore:

$$
f(n)=\sum_{k=1}^{n}(k-1)
$$

Using the arithmetic series formula:

$$
f(n)=0+1+2+\cdots+(n-1)
$$

We obtain:

$$
\boxed{f(n)=\frac{n(n-1)}{2}}
$$

However, we still need to prove that this total cost is independent of the splitting strategy.

## [3] Proof by Mathematical Induction

We want to prove that, regardless of how an integer `n` is split into ones, its total splitting cost is:

$$
\boxed{f(n)=\frac{n(n-1)}{2}}
$$

**Base Case:**

Let `n=1`.

Since no splitting is necessary:

$$
f(1)=0
$$

Substituting into our proposed formula:

$$
f(1)=\frac{1(1-1)}{2}=0
$$

Therefore, the base case holds.

**Inductive Hypothesis:**

Assume that for some positive integers `a,b`, the total cost of splitting them into ones is:

$$
f(a)=\frac{a(a-1)}{2}
$$

$$
f(b)=\frac{b(b-1)}{2}
$$

**Inductive Step:**

Consider an arbitrary integer `n`, which is split into two positive integers `a` and `b`, where:

$$
a+b=n
$$

The initial splitting cost is:

$$
C(a,b)=ab
$$

After this initial split, we must split both `a` and `b` into ones.

Therefore, the total cost is:

$$
f(n)=ab+f(a)+f(b)
$$

Substituting our inductive hypothesis:

$$
f(n)=ab+\frac{a(a-1)}{2}+\frac{b(b-1)}{2}
$$

Expanding:

$$
f(n)=\frac{2ab+a^2-a+b^2-b}{2}
$$

Rearranging:

$$
f(n)=\frac{a^2+2ab+b^2-a-b}{2}
$$

Factorising:

$$
f(n)=\frac{(a+b)^2-(a+b)}{2}
$$

Since `a+b=n`:

$$
\boxed{f(n)=\frac{n(n-1)}{2}}
$$

Therefore, the inductive step holds.

Hence, by mathematical induction:

$$
\boxed{f(n)=\frac{n(n-1)}{2}}
$$

for all positive integers `n`.

## [4] Conclusion

We have proven that regardless of the splitting strategy, the total cost of splitting an integer `n` into `n` ones is always:

$$
f(n)=\frac{n(n-1)}{2}
$$

Since every valid splitting strategy produces the same total cost, this total cost is necessarily the minimum cost.

Therefore, we can eliminate the need for Dynamic Programming and directly calculate:

$$
\boxed{\operatorname{minCost}(n)=\frac{n(n-1)}{2}}
$$

**Time Complexity:** `O(1)`

**Space Complexity:** `O(1)`
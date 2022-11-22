(define-key global-map [?\s-x] 'kill-region)
(define-key global-map [?\s-c] 'kill-ring-save)
(define-key global-map [?\s-v] 'yank)
(set-face-attribute 'region nil :background "#666" :foreground "#ffffff")
(transient-mark-mode t)

